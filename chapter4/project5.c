#include <stdio.h>

int main(void)
{
  int upc;
  int _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11;
  int first_sum, second_sum, total;

  printf("Enter the frist 11 digits of a UPC: ");
  scanf("%d", &upc);

  _1 = upc / 10000000000;
  _2 = (upc / 1000000000) % 10;
  _3 = (upc / 100000000) % 10;
  _4 = (upc / 10000000) % 10;
  _5 = (upc / 1000000) % 10;
  _6 = (upc / 100000) % 10;
  _7 = (upc / 10000) % 10;
  _8 = (upc / 1000) % 10;
  _9 = (upc / 100) % 10;
  _10 = (upc / 10) % 10;
  _11 = (upc / 1) % 10;

  first_sum = _1 + _3 + _5 + _7 + _9 + _11;
  second_sum = _2 + _4 + _6 + _8 + _10;
  total = 3 * first_sum + second_sum;

  printf("Check digit: %d\n", 9 - ((total - 1) % 10));

  return 0;
}
