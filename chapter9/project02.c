/*
2. Modify Programming Project 5 from Chapter 5 so that it uses a function to
compute the amount of income tax. When passed an amount of taxable income, the
function will return the tax due.
*/
#include <stdio.h>

float calc_income_tax(float income);

int main(void) {
  float income;

  printf("Enter your taxable income: ");
  scanf("%f", &income);

  float tax_due = calc_income_tax(income);
  printf("Tax due: $%.2f", tax_due);

  return 0;
}

float calc_income_tax(float income) {
  float tax_due;
  float overage;

  if (income < 750.00f) {
    tax_due = income * 0.01;
  } else if (income >= 750.00f && income <= 2250.00f) {
    overage = income - 750.00f;
    tax_due = 7.50 + overage * 0.02;
  } else if (income >= 2250.01f && income <= 3750.00f) {
    overage = income - 2250.00f;
    tax_due = 37.50 + overage * 0.03;
  } else if (income >= 3750.01f && income <= 5250.00f) {
    overage = income - 3750.00f;
    tax_due = 82.50 + overage * 0.04;
  } else if (income >= 5250.00f && income <= 7000.00f) {
    overage = income - 5250.00f;
    tax_due = 142.50f + overage * 0.05;
  } else {
    overage = income - 7000.00f;
    tax_due = 230 + overage * 0.06;
  }

  return tax_due;
}
