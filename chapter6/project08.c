#include <stdio.h>

int main(void) {
  int days, start;

  printf("Enter number of days in month: ");
  scanf("%d", &days);

  printf("Enter starting day of the week (1=Sun, 7=Sat): ");
  scanf("%d", &start);

  int j = 1;
  while (start > 1) {
    printf("   ");
    j++;
    start--;
  }
  for (int i = j; i <= days + j - 1; i++) {
    printf("%3d", i - j + 1);
    if (i % 7 == 0) {
      printf("\n");
    }
  }

  return 0;
}
