#include <stdio.h>

int main(void)
{
  int _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16;
  int row_sum1, row_sum2, row_sum3, row_sum4;
  int column_sum1, column_sum2, column_sum3, column_sum4;
  int diagonal_sum1, diagonal_sum2;

  printf("Enter the numbers from 1 to 16 in any order: ");
  scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &_1, &_2, &_3, &_4, &_5, &_6, &_7, &_8, &_9, &_10, &_11, &_12, &_13, &_14, &_15, &_16);

  printf("%.2d %.2d %.2d %.2d\n", _1, _2, _3, _4);
  printf("%.2d %.2d %.2d %.2d\n", _5, _6, _7, _8);
  printf("%.2d %.2d %.2d %.2d\n", _9, _10, _11, _12);
  printf("%.2d %.2d %.2d %.2d\n", _13, _14, _15, _16);

  row_sum1 = _1 + _2 + _3 + _4;
  row_sum2 = _5 + _6 + _7 + _8;
  row_sum3 = _9 + _10 + _11 + _12;
  row_sum4 = _13 + _14 + _15 + _16;

  column_sum1 = _1 + _5 + _9 + _13;
  column_sum2 = _2 + _6 + _10 + _14;
  column_sum3 = _3 + _7 + _11 + _15;
  column_sum4 = _4 + _8 + _12 + _16;

  diagonal_sum1 = _1 + _6 + _11 + _16;
  diagonal_sum2 = _4 + _7 + _10 + _13;

  printf("Row sums: %d %d %d %d\n", row_sum1, row_sum2, row_sum3, row_sum4);
  printf("Column sums: %d %d %d %d\n", column_sum1, column_sum2, column_sum3, column_sum4);
  printf("Diagonal sums: %d %d", diagonal_sum1, diagonal_sum2);
}
