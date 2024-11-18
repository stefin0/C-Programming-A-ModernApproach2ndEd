/*
17. Write a program that prints an n x n magic square (a square arrangement of the numbers
1, 2, ..., n^2 in which the sums of the rows, cols, and diagonals are all the same). The
user will specify the value of n:
This program creates a magic square of a specified size.
The size must be an odd number between 1 and 99.
Enter size of magic square: 5
17 24 1  8  15
23 5  7  14 16
4  6  13 20 22
10 12 19 21 3
11 18 25 2  9
Store the magic square in a two-dimensional array. Start by placing the number 1 in the mid-
dle of row 0. Place each of the remaining numbers 2, 3, ..., n^2 by moving up one row and
over one col. Any attempt to go outside the bounds of the array should "wrap around"
to the opposite side of the array. For example, instead of storing the next number in row -1,
we would store it in row n - 1 (the last row). Instead of storing the next number in col n.
we would store it in col 0. If a particular array element is already occupied, put the
number directly below the previously stored number. If your compiler supports variable-
length arrays, declare the array to have n rows and n cols. If not, declare the array to
have 99 rows and 99 cols.
*/
#include <stdio.h>

int main(void) {
  int size, row, col;
  int row_shift = 0;
  int col_shift = 0;

  printf("This program creates a magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99.\n");
  printf("Enter size of magic square: ");
  scanf("%d", &size);

  int arr[size][size];

  // Initialize array to all zeros
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      arr[i][j] = 0;
    }
  }

  // Create magic square
  for (int i = (size * size); i > 0; i--) {
    row = (i + row_shift) % size;
    col = ((size * size - i) + (size / 2) + col_shift) % size;

    if (arr[row][col] != 0) {
      row_shift += 2;
      col_shift -= 1;
      row = (i + row_shift) % size;
      col = ((size * size - i) + (size / 2) + col_shift) % size;
    }

    arr[row][col] = (size * size - i) + 1;
  }

  // Print array
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d\t", arr[i][j]);
    }
    printf("\n");
  }
}
