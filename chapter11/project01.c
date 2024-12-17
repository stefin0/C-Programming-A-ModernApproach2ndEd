/*
1. Modify Programming Project 7 from Chapter 2 so that it includes the following
function: void pay_amount(int dollars, int *twenties, int *tens, int *fives, int
*ones);
The function determines the smallest number of $20, $10, $5, and $1
bills necessary to pay the amount represented by the dollars parameter. The
twenties parameter points to a variable in which the function will store the
number of S20 bills required. The tens, fives, and ones parameters are similar.
*/
#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main()
{
  int dollars;
  int twenties, tens, fives, ones;

  printf("Enter a dollar amount: ");
  scanf("%d", &dollars);

  pay_amount(dollars, &twenties, &tens, &fives, &ones);

  printf("$20 bills: %d\n", twenties);
  printf("$10 bills: %d\n", tens);
  printf("$5 bills: %d\n", fives);
  printf("$1 bills: %d\n", ones);

  return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
  *twenties = dollars / 20;
  dollars = dollars - (*twenties * 20);

  *tens = (dollars / 10);
  dollars = dollars - (*tens * 10);

  *fives = (dollars / 5);
  dollars = dollars - (*fives * 5);

  *ones = (dollars / 1);
  dollars = dollars - (*ones * 1);
}
