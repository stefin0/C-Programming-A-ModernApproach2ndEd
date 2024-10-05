#include <ctype.h>
#include <stdio.h>

int main(void) {
  int hour, min;
  char meridiem;

  printf("Enter a 12-hour time: ");
  scanf("%d:%d %c", &hour, &min, &meridiem);
  meridiem = toupper(meridiem);

  if (meridiem == 'A') {
    if (hour == 12) {
      hour = 0;
    }
  } else if (meridiem == 'P') {
    if (hour != 12) {
      hour += 12;
    }
  }
  printf("Equivalent 24-hour time: %02d:%.2d\n", hour, min);

  return 0;
}
