#include <stdio.h>

int main(void) {
  float income;

  printf("Enter your taxable income: ");
  scanf("%f", &income);

  printf("Tax due: $");
  if (income < 750.00f) {
    printf("%.2f", income * 0.01);
  } else if (income < 2250.00f) {
    printf("%.2f", 7.50 + income * 0.02);
  } else if (income < 3750.00f) {
    printf("%.2f", 37.50 + income * 0.03);
  } else if (income < 5250.00f) {
    printf("%.2f", 82.50 + income * 0.04);
  } else if (income < 7000.00f) {
    printf("%.2f", 142.50f + income * 0.05);
  } else {
    printf("%.2f", 230 + income * 0.06);
  }

  return 0;
}
