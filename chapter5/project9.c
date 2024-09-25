#include <stdio.h>

int main(void) {
  int mm1, dd1, yy1;
  int mm2, dd2, yy2;

  printf("Enter first date (mm/dd/yy): ");
  scanf("%d/%d/%d", &mm1, &dd1, &yy1);

  printf("Enter second date (mm/dd,yy): ");
  scanf("%d/%d/%d", &mm2, &dd2, &yy2);

  if (yy1 < yy2 || (yy1 == yy2 && mm1 < mm2) || (yy1 == yy2 && mm1 == mm2 && dd1 < dd2)) {
    printf("%d/%d/%.2d is earlier than %d/%d/%.2d", mm1, dd1, yy1, mm2, dd2, yy2);
  } else {
    printf("%d/%d/%.2d is earlier than %d/%d/%.2d", mm2, dd2, yy2, mm1, dd1, yy1);
  }

  return 0;
}
