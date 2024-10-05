#include <stdio.h>

int main(void) {
  printf("sizeof(int): %llu\n", sizeof(int));
  printf("sizeof(short): %llu\n", sizeof(short));
  printf("sizeof(long): %llu\n", sizeof(long));
  printf("sizeof(float): %llu\n", sizeof(float));
  printf("sizeof(double): %llu\n", sizeof(double));
  printf("sizeof(long double): %llu\n", sizeof(long double));

  return 0;
}
