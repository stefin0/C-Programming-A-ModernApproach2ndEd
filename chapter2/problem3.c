#include <stdio.h>

int main(void)
{
  float amount;

  printf("Enter an amount: ");
  scanf("%f", &amount);

  float amount_with_tax = amount * 1.05;

  printf("With tax added: $%f", amount_with_tax);
}
