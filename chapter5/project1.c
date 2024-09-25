#include <stdio.h>

int main(void) {
  int num;

  printf("Enter a number: ");
  scanf("%d", &num);

  printf("The number %d has ", num);
  if (num >= 0 && num <= 9) {
    printf("%d", 1);
  } else if (num >= 10 && num <= 99) {
    printf("%d", 2);
  } else if (num >= 100 && num <= 999) {
    printf("%d", 3);
  } else if (num >= 1000 && num <= 9999) {
    printf("%d", 4);
  }
  printf(" digits.");

  return 0;
}
