#include <stdio.h>
#define min(a, b) a < b ? a : b
// divide and conquer:
// - conceptualize how a program can be broken down into smaller
// parts

// get a, b, c from command line
// compute g = gcd(a, b)
// if (c is not a multiple of gcd)
//      no solutions exist, exit
// run extended solution algorithm on a, b
// rescale x and y output by (c/g)
// -> extended Euclidian algorithm:
// finds integers x, y such that
// ax + by = gcd(a, b)

// static keyword variables have 2 meaning, depending on where its declared
// - outside function, static variables only visible in that file (cannot extern)
// - inside function they
//      -> are still local to that function
//      -> are initialized only during program initalization
//      -> do not get reinitiakized with each function call
//
//  register keyword variables
//  - during execution, data processed in registers
//  - explicitly store commonly used data
//  -> must be a simple type
//  -> only local vars and funciton args
//  -> excess/unallowed register declaration ignored, compiled as reg var
//  -> do not reside in addressed memory, pointer to reg var illegal

int main() {
    register int a = 3;
    register int b = 5;
    
    printf("a = %d b = %d\n", a, b);
    return 0;
}
