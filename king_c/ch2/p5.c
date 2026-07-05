/* 
 * Asks the "USER" for an amount in U.S. dollars
 * prints how to pay that amount with the
 * smallest amount of $1, $5, $10, $20.
 */

#include <stdio.h>

int main(void)
{
    int amount = 0;
    printf("Enter a dollar amount: ");
    scanf("%d", &amount);
    int twenty = amount / 20;
    int ten = (amount - 20 * twenty) / 10;
    int five = (amount - 20 * twenty - 10 * ten) / 5;
    int one = (amount - 20 * twenty - 10 * ten - 5 * five);
    printf("In order to pay $%d with the least amount of bills,", amount);
    printf(" you will need:\n");
    printf("%d twenty, %d ten, %d five, %d one dollar bills.\n", twenty, ten, five, one);
    return 0;
}
