#include <stdio.h>

// conversion specification can have the form:
// %m.pX or %-m.pX
// where m and p are integer constants and X is a letter.
// both m and p are optional.
// m -> minimum field width
// p -> precision specification
// X -> conversion specification

void ex_1() {
    // what output do the following calls to printf produce?
    // _ used to represent whitespace
    printf("<%6d, %4d>\n", 86, 1040); // ____86 1040
    printf("<%12.5e>\n", 30.253);     // _3.02530e+01
    printf("<%.4f>\n", 83.162);       // 83.1620
    printf("<%-6.2g>\n", .0000009979); // 1e-06_
}

void ex_2() {
    // write calls to printf that display a float variable x
    // in the following formats
    float x = 3.14159265358979;
    float y = 45.4545;
    // exponential notation, ljust in a field of size 8, one digit after
    // decimal point
    printf("<%-8.1e>\n", x);
    // exponential notation, rjust in a field of size 10, six digits after
    // decimal point
    printf("<%10.6e>\n", x);
    // fixed decimal notation, ljust in a field of size 8, 3 digits after
    // decimal point
    printf("<%-8.3g>\n", y);
    // fixed decimal notation, rjust in a field of size 6, no digits after
    // decimal point
    printf("<%6.0g>\n", y);
}

void ex_3() {
    // for each of the following pairs of scanf format strings, indicate
    // whether or not the two strings are equivalent. If they're not,
    // show how they can be distinguished.
    // (a) "%d" vs " %d" -> no difference
    // ========================================================================
    // (b) "%d-%d-%d" vs "%d -%d -%d" -> the '-' character is not whitespace,
    // so in the first, you are tied to the exact format. In the second,
    // any amount of whitespace is equivalent to one space
    // ========================================================================
    // (c) "%f" vs "%f   " -> the second will add the whitespace as extra 
    // precision for the float, kind of like .<whitespace>f
    // ========================================================================
    // (d) "%f,%f" vs "%f, %f"
    float a, b;
    scanf("%f,%f", &a, &b);
    printf("%f %f\n", a, b);
}

int main() {
    ex_3();
    return 0;
}

