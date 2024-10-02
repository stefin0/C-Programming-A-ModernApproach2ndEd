#include <stdio.h>

int main(void) {
  float num;
  float max = -1;

  do {
    printf("Enter a number: ");
    scanf("%f", &num);
    if (num > max) {
      max = num;
    }
  } while (num > 0 || num != 0);

  printf("The largest number entered was %f", max);

  return 0;
}
