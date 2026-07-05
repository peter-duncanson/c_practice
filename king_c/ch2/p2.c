// Ask the user to enter a dollars and cents amount, then displays the
// amount with 5% tax added
#include <stdio.h>

int main(void)
{
    int dollars;
    int cents;
    
    printf("Enter dollars: ");
    scanf("%d", &dollars);

    printf("\nEnter cents: ");
    scanf("%d", &cents);

    float amount = dollars + (0.01 * cents);

    printf("\nAmount: %.2f\n", amount);
    printf("Amount with 5 tax: %.2f\n", amount + (amount * 0.05));

    return 0;
}
