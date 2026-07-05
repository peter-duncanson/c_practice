#include <stdio.h>
// C is a weakly typed language; allows implicit converstions and
// forced casting (potentially dangerous)

// ==== Big endian and little endian ====
// - Big endian ->
//      MSB occupy the lower address
//      Networks generally use this order, so its called network order
// - Little endian ->
//      LSB occupy the lower address
//      used on all x86 processors

// POP QUIZ
// int x = 017; int y = 12 /* x > y? -> yes */
// short int s = 0xFFFF12; /* correct? -> no */
// char c = -1; unsigned char uc = -1; /* correct? -> no */
// puts("hel" + "lo"); puts("hel""lo"); /* which is correct? -> second */
// enum sz{S=0, L=3, XL}; /* what is the value of XL? -> 4 */
// enum sz{S = 0, L = -3, XL}; /* what is the value of XL? -> -2 */

int main() {
    int x = 017;
    int y = 12;
    int x_more_than_y = x > y ? 1 : 0;
    printf("X > Y is %d\n", x_more_than_y);

    // will overflow
    short s = 0xFFFF12;
    printf("%d\n", s);

    // this is fine
    char c = -1;
    // this will underflow to 255
    unsigned char uc = -1;
    printf("char c = %d\nunsigned char uc = %d\n", c, uc);

    // this will cause a compilation error, cannot add char* + char*
    // puts("hel" + "lo");
    // this is ok
    puts("hel""lo");

    // enum sz{S = 0, L = 3, XL};
    // S = 0, L = 3, XL = 4 -> follows L
    // printf("S = %d\nL = %d\nXL = %d\n", S, L, XL);

    enum sz{S = 0, L = -3, XL};
    // S = 0, L = -3, XL = -2 -> same direction as a positive
    printf("S = %d\nL = %d\nXL = %d\n", S, L, XL);
    
    return 0;
}
// Conditional expression & the turnary operator
// if (cond)
//      x = something;
// else
//      x = something else;
//
// turnary operator is syntactic sugar for this
//
// sign = x > 0 ? 1 : -1;
// is equivalent to
// if (x > 0)
//      sign = 1;
// else
//      sign = -1;
//
// isodd = x % 2 == 1 ? 1 : 0;
// is equivalent to
// if (x % 2 == 1)
//      isodd = 1;
// else
//      isodd = 0;
