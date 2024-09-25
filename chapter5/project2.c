#include <stdio.h>

int main(void) {
  int hour, min;

  printf("Enter a 24-hour time: (hh:mm): ");
  scanf("%d:%d", &hour, &min);

  printf("Equivalent 12-hour time: ");
  if (hour == 0 || hour == 24) {
    printf("%d:%.2d AM", 12, min);
  } else if (hour < 12) {
    printf("%d:%.2d AM", hour, min);
  } else if (hour < 24) {
    printf("%d:%.2d PM", hour - 12, min);
  }

  return 0;
}
