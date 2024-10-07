/* Checks numbers for repeated digits */
#include <stdbool.h> /* C99 only */
#include <stdio.h>

int main(void) {
  bool digit_seen[10] = {false};
  int digit;
  long n;
  long n_arr[100] = {0};

  printf("Enter number(s). <= 0 to quit: ");
  scanf("%ld", &n);
  n_arr[0] = n;
  int n_arr_len = 1;
  while (n_arr_len < 100) {
    scanf("%ld", &n);
    if (n <= 0) {
      break;
    }
    n_arr[n_arr_len] = n;
    n_arr_len++;
  }

  for (int i = 0; i < n_arr_len; i++) {
    n = n_arr[i];
    printf("\n%ld\n", n);

    while (n > 0) {
      digit = n % 10;
      if (digit_seen[digit]) {
        break;
      }
      digit_seen[digit] = true;
      n /= 10;
    }

    if (n > 0) {
      printf("Repeated digit\n");
    } else {
      printf("No repeated digit\n");
    }

    // reset digit_seen[]
    for (int j = 0; j < 10; j++) {
      digit_seen[j] = false;
    }
  }

  return 0;
}
