#include <stdio.h>

void convert_date() {
    int month, day, year;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d / %d / %d", &month, &day, &year);
    printf("You entered the date %.4d%.2d%.2d\n", year, month, day);
}

void format_product_info() {
    int item_number, month, day, year;
    float unit_price;
    printf("Enter item number: ");
    scanf("%d", &item_number);
    printf("Enter unit price: $");
    scanf("%f", &unit_price);
    unit_price = unit_price > 9999.99 ? 9999.99 : unit_price;
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d / %d / %d", &month, &day, &year);
    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%d\t\t$%7.2f\t%-.2d/%-.2d/%-.4d\n", 
            item_number, unit_price, month, day, year);
}
