/* Checks numbers for repeated digits */
#include <stdbool.h> /* C99 only */
#include <stdio.h>

#define SIZE ((int)(sizeof(digit_seen) / sizeof(digit_seen[0])))

int main(void) {
  int digit_seen[10] = {0};
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    digit_seen[digit] += 1;
    n /= 10;
  }

  printf("Digit:       ");
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", i);
  }

  printf("\nOccurrences: ");
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", digit_seen[i]);
  }

  return 0;
}
