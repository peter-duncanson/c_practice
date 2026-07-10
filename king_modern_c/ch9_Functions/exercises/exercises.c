// =============================================================================
// C Programming: A Modern Approach - K.N. King
// Chapter 8: Functions - Exercises
// 06/09/26
// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include "exercises.h"
// =============================================================================
// (1) The following function, which computes the area of a triangle, contains
// two errors. Locate the errors and show how to fix them.
//
// double triangle_area(double base, height) <- no type for height
// double product; <- local variable delcared outside of function body
// {
//     product = base * height;
//     return product / 2;
// }
//
// double triangle_area(double base, double height)
// {
//     return ((base * height) / 2);
// }
// =============================================================================

// =============================================================================
// (2) Write a function called check(x, y, n) that returns 1 if both x and y 
// fall between 0 and n - 1, inclusive. The function should return 0 otherwise.
// Assume that x, y and m are all of tyoe int.

int check(int x, int y, int n)
{
     return (x >= 0 && x <= (n - 1) && y >= 0 && y <= (n - 1)) ? 1 : 0;
}

// =============================================================================

// =============================================================================
// (3) Write a function gcd(m, n) that calculates the greatest common divisor of
// the integers m and n.

int gcd(int m, int n)
{
     int temp;

     if (m < n)
     {
         temp = m;
         m = n;
         n = temp;
     }

     while (m)
     {
         temp = m;
         m = n % m;
         n = temp;
     }

     return n;
}

// =============================================================================

// =============================================================================
// (4) Write a function day_of_year(month, day, year) that returns the day of
// the year (an integer between 1 and 366) specified by the three arguments

int day_of_year(int month, int day, int year)
{
    int ans = 0;

    if ((year % 4 == 0) && (year % 100 != 0)) ans++;

    switch (month)
    {
        case 2:
            ans += 31;
            break;
        case 3:
            ans += 59;
            break;
        case 4:
            ans += 90;
            break;
        case 5:
            ans += 120;
            break;
        case 6:
            ans += 151;
            break;
        case 7:
            ans += 181;
            break;
        case 8:
            ans += 212;
            break;
        case 9:
            ans += 243;
            break;
        case 10:
            ans += 273;
            break;
        case 11:
            ans += 304;
            break;
        case 12:
            ans += 334;
            break;

    }
    return (ans + day);
}

// =============================================================================

// =============================================================================
// (5) Write a function num_digits(n) that returns the number of digits in n.
// (a positive integer).

int num_digits(int n)
{
    int ans = 0;

    while (n)
    {
        n /= 10;
        ans++;
    }

    return ans;
}

// =============================================================================

// =============================================================================
// (6) Write a function digit(n, k) that returns the kth digit (from the right)
// in n (a positive intgeger). For example, digit(829, 1) returns 9,
// digit(829, 2) returns 2, and so on. If k is greater than the number of digits
// in n, have the function return 0.

int digit(int n, int k)
{
    int i, ans;

    for (i = 0; i < k; i++)
    {
        ans = n % 10;
        n /= 10;
    }

    return (n < 0) ? 0 : ans;
}

// =============================================================================

// =============================================================================
// (7) Suppose that the function f has the following definition:
// int f(int a, int b) { ... }
// Which of the following statements are legal? (Assume that i had type int and
// x has type double.)
//
//      (a) i = f(83, 12);       <- legal, obviously
//      (b) x = f(83, 12);       <- legal, returned int will be promoted
//      (c) i = f(3.15, 9.28);   <- legal, args will be truncated
//      (d) x = f(3.15, 9.28);   <- legal, combination of prev. two
//      (e) f(83, 12);           <- legal, return value dicarded
//
// =============================================================================

// =============================================================================
// (8) Which of the following would be valid prototypes for a function that
// returns nothing and has one double parameter?
//
//      (a) void f(double x); <- valid
//      (b) void f(double);   <- parameter not named
//      (c) void f(x);        <- parameter type not specified
//      (d) f(double x);      <- return type not specified
//
// =============================================================================

// =============================================================================
// (9) What will be the output of the following program?
//
// #include <stdio.h>
//
// int main(void)
// {
//      int i = 1, j = 2;
//
//      swap(i, j);
//      printf("i = %d, j = %d\n", i, j);
//      return 0;
// }
//
// void swap(int a, int b)
// {
//      int temp = a;
//      a = b;
//      b = temp;
// }
//
// a and b are passed by value into swap, so they are only modified in swap's
// scope. The output of the program is:
// i = 1, j = 2
// =============================================================================

// =============================================================================
// (10) Write functions that return the following values. (Assume that a and n
// are parameters, where a is an array of int values and n is the length of the
// array.)
//
//      (a) The largest element in a.
//      (b) The average of all elements in a.
//      (c) The number of positive elements in a.

int largest(int a[], int n)
{
    int i, ans = a[0];

    for (i = 1; i < n; i++)
    {
        if (a[i] >= ans) ans = a[i];
    }

    return ans;
}

float average(int a[], int n)
{
    int i;
    float ans = 0.0;

    for (i = 0; i < n; i++)
    {
        ans += a[i];
    }

    return ans / n;
}

int num_positive(int a[], int n)
{
    int i, ans = 0;

    for (i = 0; i < n; i++)
    {
        if (a[i] > 0) ans++;
    }

    return ans;
}

// =============================================================================

// =============================================================================
// (11) Write the following function:
//
// float compute_GPA(char grades[], int n);
//
// The grades array will contain letter grades (A, B, C, D or F, either upper
// or lower case); n is the length of the array. The function should return the
// average of the grades (assume that A = 4, B = 3, C = 2, D = 1, and F = 0).

float compute_GPA(char grades[], int n)
{
    int i;
    float gpa = 0.0;

    for (i = 0; i < n; i++)
    {
        switch (toupper(grades[i]))
        {
            case 'A':
                gpa += 4.0;
                break;
            case 'B':
                gpa += 3.0;
                break;
            case 'C':
                gpa += 2.0;
                break;
            case 'D':
                gpa += 1.0;
                break;
        }
    }

    return gpa / n;
}

// =============================================================================

// =============================================================================
// (12) Write the following function:
//
// double inner_product(double a[], double b[], int n);
//
// The function should return a[0] * b[0] + a[1] * b[1] + ... + a[n-1] * b[n-1].

double inner_product(double a[], double b[], int n)
{
    int i;
    double ans = 0.0;

    for (i = 0; i < n; i++)
    {
        ans += (a[i] * b[i]);
    }

    return ans;
}

// =============================================================================

// =============================================================================
// (13) Write the following function, which evaluates a chess position:
//
// int evaulate_position(char board[8][8]);
//
// board represents a configuration of pieces on a chessboard, there the letters
// K, Q, R, B, N, P represent White pieces, and the letters k, q, r, b, n and p
// represent Black pieces. evaluate_position should sum the values of the pieces
// on the board according to:
// Q = 9
// R = 5
// B = 3
// N = 3
// P = 1
// The function will return the difference between the value of the White pieces
// and Black pieces. This value will be positive if White has the advantage in
// material and negative is Black does.

int evaluate_position(char board[8][8])
{
    int i, j, score_black = 0, score_white = 0;

    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
        {

            switch(board[i][j])
            {
                case 'P':
                    score_white += 1;
                    break;
                case 'p':
                    score_black += 1;
                    break;
                case 'N':
                case 'B':
                    score_white += 3;
                    break;
                case 'n':
                case 'b':
                    score_black += 3;
                    break;
                case 'R':
                    score_white += 5;
                    break;
                case 'r':
                    score_black += 5;
                    break;
                case 'Q':
                    score_white += 9;
                    break;
                case 'q':
                    score_black += 9;
                    break;

            };
        }
    return score_white - score_black;
}

// =============================================================================

// =============================================================================
// (14) The following function is supposed to return true if any element of the
// array a has the value 0 and false if all of the elements are nonzero. Sadly,
// it contains an error. Find the error and show how to fix it:
//
// bool has_zero(int a[], int n)
// {
//      int i;
//
//      for (i = 0; i < n; i++)
//          if (a[i] == 0)
//              return true;
//          else             <- function returns false prematurely    
//              return false;
// }
//
// The function will return false as soon as it encounters the first nonzero
// element. The array could be something like { 1, 0, 0, 0, 0 } and the function
// would return false. The correct function would be:
//
// bool has_zero(int a[], int n)
// {
//      int i;
//
//      for (i = 0; i < n; i++)
//          if (a[i] == 0) return true;
//
//      return false;
// }
//
// =============================================================================

// =============================================================================
// (15) The following (rather confusing) function finds the median of three
// numbers. Rewrite the function so it has just one return statement.
//
// double median(double x, double y, double z)
// {
//      if (x <= y)
//          if (y <= z) return y;
//          else if (x <= z) return z;
//      if (z <= y) return y;
//      if (x <= z) return x;
//      rerutn z;
// }

double median(double x, double y, double z)
{
    double ans;
    
    if (x <= y)
    {
        if (y <= z) ans = y;
        else ans = (x <= z) ? z : x;
    }

    else if (y <= x) 
    {
        if (x <= z) ans = x;
        else ans = (y <= z) ? z : y;
    }
    
    return ans;
}

// =============================================================================

// =============================================================================
// (16) Condense the fact function with Ternary operator.
//
// int fact(int n)
// {
//      if (n <= 1)
//          return 1;
//      else
//          return n * fact(n - 1);
// }

int fact(int n)
{
    return (n <= 1) ? 1 : n * fact(n - 1);
}

// =============================================================================

// =============================================================================
// (17) Rewrite the fact function so that it's no longer recursive.

int fact_no_recursion(int n)
{
    int i, k = 1;    
    
    for (i = n; i > 1; i--)
    {
        k *= i;
    }

    return k;
}

// =============================================================================

// =============================================================================
// (18) Write a recursive version of the gcd function.

// int gcd(int a, int b)
// {
//      int temp;
//
//      if (a < b)
//      {
//          temp = a;
//          a = b;
//          b = temp;
//      }
//
//      while (a)
//      {
//          temp = a;
//          a = b % a;
//          b = temp;
//      }
//
//      return n;
// }

int gcd_recursive(int a, int b)
{
    if (!a) return b;
    return gcd_recursive(b % a, a);
}

// =============================================================================

// =============================================================================
// (19) Consider the following "mystery" function:

void pb(int n)
{
     if (n != 0)
     {
         pb(n / 2);
         putchar('0' + n % 2);
     }
}

// Trace the execution of the function by hand, then write a program that calls
// the function, passing a number entered by the user. What does the function
// do?
//
// The function repeatedly calls itself when the input is nonzero, building a 
// call stack of n / 2, so if input was 15:
// pb(15)
// pb(7)
// pb(3)
// pb(1)
// pb(0) <- now unwind
// '0' + 1
// '0' + 1
// '0' + 1
// '0' + 1
// output:
// 1111
// It prints the number in binary!!
// =============================================================================
