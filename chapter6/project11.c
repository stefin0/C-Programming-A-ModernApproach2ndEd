#include <stdio.h>

int main(void) {
  float n;
  float fact = 1.0f;
  float e = 1.0f;

  printf("Enter an integer: ");
  scanf("%f", &n);

  for (int i = 1; i <= n; i++) {
    fact *= i;
    e += 1 / fact;
  }

  printf("e = %.3f", e);

  return 0;
}
