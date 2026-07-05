#include <stdio.h>

void find_largest() {
    // Project 1
    // Write a program that finds the largest in a series of numbers
    // entered by the user. The program must prompt the user to
    // enter the numbers one by one. When the user enters 0 or a
    // negative number, the program must display the largest
    // non-negative number entered.
    float i = 1;
    float largest = i;
    while (1) {
        printf("Enter a number: ");
        scanf("%f", &i);
        if (i <= 0) {
            break;
        }
        else if (i > largest) {
            largest = i;
        }
    }
    printf("The largest number entered was %f\n", largest);
}

void gcd() {
    // Project 2
    // Write a program that asks the user to enter two integers,
    // then calculates and displays their GCD
    // using Euclid's algorithm:
    int i, j;
    printf("Enter two integers: ");
    scanf("%d %d", &i, &j);
    printf("The GCD of %d and %d is ", i, j);

    if (i < j) {
        int temp = j;
        j = i;
        i = temp;
    }

    while (j) {
        int temp = j;
        j = j % i;
        i = temp;
    }
    printf("%d\n", i);
}

void reduce_fraction() {
    // Write a program that asks the user to enter a fraction,
    // then reduce the fraction to lowest terms.

    int numerator, denominator, gcd, i, j;

    printf("Enter a fraction: ");
    scanf("%d/%d", &numerator, &denominator);

    if (numerator < denominator) {
        i = numerator;
        j = denominator;
    }
    else {
        i = denominator;
        j = numerator;
    }

    // Euclid's algorithm
    while (j) {
        gcd = j;
        j = j % i;
        i = gcd;
    }

    printf("In lowest form: %d/%d\n", numerator / gcd, denominator / gcd);
}
