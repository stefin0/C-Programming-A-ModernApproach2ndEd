#include <stdio.h>

int main(void)
{
  int item_number;
  float unit_price;
  int mm, dd, yyyy;

  printf("Enter item number: ");
  scanf("%d", &item_number);

  printf("Enter unit price: ");
  scanf("%f", &unit_price);

  printf("Enter purchase date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &mm, &dd, &yyyy);

  printf("Item\tUnit\tPurchase\n");
  printf("\tPrice\tDate\n");
  printf("%-d\t$%6.2f\t%d/%d/%d", item_number, unit_price, mm, dd, yyyy);
}
