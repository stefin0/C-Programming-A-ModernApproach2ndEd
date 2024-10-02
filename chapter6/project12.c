#include <stdio.h>

int main(void) {
  float n;
  float fact = 1.0f;
  float term = 9999;
  float e = 1.0f;

  printf("Enter a small floating point number: ");
  scanf("%f", &n);

  for (int i = 1; term > n; i++) {
    fact *= i;
    term = 1 / fact;
    e += term;
  }

  printf("e = %.3f", e);

  return 0;
}
