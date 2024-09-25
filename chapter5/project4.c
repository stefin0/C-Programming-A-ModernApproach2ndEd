#include <stdio.h>

int main(void) {
  int knots;

  printf("Enter a wind speed (in knots): ");
  scanf("%d", &knots);

  printf("The wind speed is ");
  if (knots < 1) {
    printf("calm.");
  } else if (knots <= 3) {
    printf("light air.");
  } else if (knots <= 27) {
    printf("breeze");
  } else if (knots <= 47) {
    printf("gale.");
  } else if (knots <= 63) {
    printf("stormy.");
  } else {
    printf("hurricane.");
  }

  return 0;
}
