#include <stdio.h>

int main(void) {
  int _1, _2, _3, _4;
  int min, max;

  printf("Enter four integer: ");
  scanf("%d %d %d %d", &_1, &_2, &_3, &_4);

  min = _1;
  max = _1;

  if (_2 > max) {
    max = _2;
  }
  if (_3 > max) {
    max = _3;
  }
  if (_4 > max) {
    max = _4;
  }

  if (_2 < min) {
    min = _2;
  }
  if (_3 < min) {
    min = _3;
  }
  if (_4 < min) {
    min = _4;
  }

  printf("Largest: %d\n", max);
  printf("Smallest: %d\n", min);

  return 0;
}
