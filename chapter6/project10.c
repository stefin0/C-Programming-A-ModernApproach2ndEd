#include <stdio.h>

int main(void) {
  int earliest_month = 9999, earliest_day = 9999, earliest_year = 9999;
  int mm, dd, yy;

  do {
    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &mm, &dd, &yy);

    if (mm == 0 && dd == 0 && yy == 0) {
      break;
    }

    if (yy < earliest_year || (yy == earliest_year && mm < earliest_month) ||
        (yy == earliest_year && mm == earliest_month && dd < earliest_day)) {
      earliest_month = mm;
      earliest_day = dd;
      earliest_year = yy;
    }
  } while (1);

  printf("%d/%d/%02d is the earliest date", earliest_month, earliest_day,
         earliest_year);

  return 0;
}
