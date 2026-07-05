// preprocessor macros begin with the # character
// #define MSG "hello, 6.087 students"
// define can take arguments and be treated like a function
// #define add3(x, y, z) ((x) + (y) + (z)) 
// compiler performs inline replacement, not suitable for recursion

// conditional preprocessor macros can control which lines are compiled
// - evaluated before code itself is compiled so conditions must be 
// preprocessor defines or literals
// - the 'gcc' option -Dname=value sets a preprocessor define that can
// be used
// used in header files to ensure declarations happen only once

#include <stdio.h>


int main() {
    // output text to the console window (stdout) and end the line.
    // puts("Hello, 6.087 students");
    
    // alternatively, store the sting in a variable first
    const char msg[] = "hello, 6.087 students";

    // strings stored as a character array
    // null terminated: last char in array is '\0' null

    // stdout, stdin: console input and output streams
    // - puts(string) -> print string to stdout
    // - putchar(char) -> print char to stdout
    // - char = getchar() -> return char from stdin
    // - string = gets(string) -> reasd line from stdin to string
    puts(msg);
    return 0;
}
