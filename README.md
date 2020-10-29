# Grade Level Comprehension: Arrays using C
### Homework from [Harvard's Introduction to Computer Science CS50 hosted on eDX](https://www.edx.org/course/cs50s-introduction-to-computer-science)
### 🎓 [Problem Set 2](https://cs50.harvard.edu/x/2020/psets/2/)
- [Readability](https://cs50.harvard.edu/x/2020/psets/2/readability/): Estimation of grade level required to comprehend any text that is inputted via command line
- I wrote all the code in each file. No code was provided by the instructor.

![Readability Program Demo](images/demo.gif)

## 💡Lessons Learned
- Working with [ASCII values](https://www.ascii-code.com/), which is one step above binary code (lowest level)
- Strings are an abstraction for an array of characters
- Applying knowledge of null terminating character at end of array of characters in C
- Deconstructing sentences into words and words into characters

## 🕹 How to Use
To run this project locally:
- In your terminal, navigate to the Readability folder and run the following commands
```
$ clang -o readability readability.c
$ ./readability
```
The program will prompt you input your sample text after `Text:`. Note that the maximum character count is 350.
```
$ Text: A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains.
```
The expected result for the above example is
```
$ Grade 16+
```