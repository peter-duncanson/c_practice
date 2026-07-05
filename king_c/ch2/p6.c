/* 
 * Calculates the remaining balance on a loan after the
 * first, second, and third monthly payments.
 */

#include <stdio.h>

int main(void)
{
    float loanAmount = 0;
    float interestRate = 0;
    float monthlyPayment = 0;

    printf("Enter loan amount: ");
    scanf("%f", &loanAmount);
    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthlyPayment);

    float monthlyInterestRate = interestRate / 1200.0f; 

    /* Amounts remaining after payments */
    float remainingAfterFirst = loanAmount - monthlyPayment + (loanAmount * monthlyInterestRate);
    float remainingAfterSecond = remainingAfterFirst - monthlyPayment + (remainingAfterFirst * monthlyInterestRate);
    float remainingAfterThird = remainingAfterSecond - monthlyPayment + (remainingAfterSecond * monthlyInterestRate);

    printf("\n\t\tPayment:\t\tRemaining:\r\n");
    printf("\t\t    1\t\t\t$%0.2f\r\n", remainingAfterFirst);
    printf("\t\t    2\t\t\t$%0.2f\r\n", remainingAfterSecond);
    printf("\t\t    3\t\t\t$%0.2f\r\n\n", remainingAfterThird);
    return 0;
}
