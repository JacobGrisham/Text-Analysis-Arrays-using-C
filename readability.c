// Includes
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Delcare function
int get_index(char *s);
char *get_string(const char *prompt);

int main(void)
{
    // Prompt user for text input
    char *text = get_string("Text: ");

    // Declare function
    int index = get_index(text);

    // Print output, which is the grade level of the provided text
    // If index number is 16 or higher
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    // If the index number is less than 1
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    // Final case
    else
    {
        printf("Grade %d\n", index);
    }
}

int get_index(char *s)
{
    // Declare variable to store the number of letters.
    int letters = 0;
    // Declare variable to store the number of sentences.
    int sentences = 0;
    // Declare variable to store the number of words.
    int words = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        // Increment letter count
        char ch = s[i];
        if (isalpha(ch))
        {
            letters++;
        }

        // Increment word count
        if (isspace(ch))
        {
            words++;
        }

        // Increment Sentences
        if (ch == '.' || ch == '!' || ch == '?')
        {
            sentences++;
        }
    }

    // Account for last word since the word increment for loop misses the last word
    words++;

    // Declare and define variable for average number of letters per 100 words in the text
    float L = (letters * 100.0f) / words;

    // Declare and define variable for average number of sentences per 100 words in the text
    float S = (sentences * 100.0f) / words;

    // Declare and define variable calculated from the Coleman-Liau index
    return round(0.0588 * L - 0.296 * S - 15.8);
}

// get_string function. Source: https://stackoverflow.com/questions/48282630/troubles-creating-a-get-string-function-in-c
char *get_string(const char *prompt)
{
    char temp[350] = ""; // Maximum number of characters
    int size,count;
    while ( 1)
    {
        printf ( "%s",prompt);
        if ( fgets ( temp, sizeof temp, stdin)) {
            if ( !strchr ( temp, '\n')) {//no newline
                printf("\x1B[31mError\x1B[0m: too long.\n%s",prompt);
                size = strlen ( temp);
                do {
                    fgets ( temp, sizeof temp, stdin);//read more and discard
                    size += strlen ( temp);
                } while (!strchr ( temp, '\n'));//loop until newline found
                printf("size :%i\n",size);
                continue;//re prompt
            }
            break;
        }
        else {
            fprintf ( stderr, "fgets problem\n");
            return NULL;
        }
    }

    temp[strcspn ( temp,"\n")] = '\0';//remove newline
    char *word = malloc(strlen ( temp) + 1);
    strcpy ( word, temp);
    return word;
}