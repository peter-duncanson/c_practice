/* 
 * Practical Programming in C
 * Problem Set 1
 */
#include <stdio.h>

void hello() {
    printf("Hello, 6.087 students\n");
}

int main() {
    hello();
    return 0;
}

/* Problem 1.1
 * (a)  What do curly braces denote in C? Why does it make sense
 *      to use curly braces to surround the body of a function?
 *
 *      -> Curly braces group blocks of related code together.
 *      They allow a function name to be tied to a block of
 *      code. The define scope and variable scope.
 *
 * (b)  Describe the difference between the literal values
 *      7, "7", and '7'.
 *
 *      -> 7 is an integer type, "7" is a null terminated string
 *      literal, '7' is a char type, ASCII code 55
 *
 * (c)  Consider the statement:
 *      double ans = 10.0 + 2.0 / 3.0 - 2.0 * 2.0;
 *      Rewrite this statement, inserting parentheses to ensure
 *      that ans = 11.0 upon evaluation of this statement.
 *
 *      -> double ans = 10.0 + (2.0 / ((3.0 - 2.0) * 2.0));
 *
 * Problem 1.2
 * Consider the statement
 * double ans = 18.0 / squared(2 + 1);
 *
 * For each of the four versions of the function macro squared(),
 * write the corresponding value of ans.
 *
 * 1. #define squared(x) x * x
 *    double ans = 18.0 / 2 + 1 * 2 + 1;
 *    ans = 12.0;
 * 2. #define squared(x) (x * x)
 *    double ans = 18.0 / (2 + 1 * 2 + 1);
 *    ans = 3.6;
 * 3. #define squared(x) (x) * (x)
 *    double ans = 18.0 / (2 + 1) * (2 + 1);
 *    ans = 18.0;
 * 4. #define squared(x) ((x) * (x))
 *    double ans = 18.0 / ((2 + 1) * (2 + 1));
 *    ans = 2.0;
 *
 * Problem 1.3
 * Write the "Hello 6.087 students" program described in lecture
 * in your favorite text editor then compile and execute it.
 *
 * Problem 1.4
 * The following lines of code, when arranged in the proper
 * sequence, output the message "All your base are belong to us."
 *
 * 1. return 0;
 * 2. const char msg[] = MSG1;
 * 3. }
 * 4. #define MSG1 "All your base are belong to us!"
 * 5. int main() {
 * 6. #include <stdio.h>
 * 7. puts(msg);
 *
 * #include <stdio.h>
 * #define MSG1 "All your base are belong to us!"
 *
 * int main() {
 *      const char msg[] = MSG1;
 *      puts(msg);
 *      return 0;
 * }
 *
 * Problem 1.5
 * For each of the following statements, explain why it is not
 * correct, and fix it.
 * (a)  #include <stdio.h>; -> Preprocessor macros like include
 *      should not be terminated with a semicolon.
 * (b)  int function(void arg1) {
 *          return arg1 - 1;
 * } -> void is not a type of an actual piece of data
 * (c)  #define MESSAGE = "Happy new year!"
 *      puts(MESSAGE) -> The define statement does not have an
 *      assignment operator.
 */


