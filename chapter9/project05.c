/*
Modify Programming Project 17 from Chapter 8 so that it includes the following
functions: void create_magic_square(int n, char magic_square[n][n]); void
print_magic_square(int n, char magic_square[n][n] ); After obtaining the number
n from the user, main will call create_magic_square. passing it an n x n array
that is declared inside main. create_magic_square will fill the array with the
numbers 1, 2, ..., n^2 as described in the original project, main will then call
print_magic_square, which will display the array in the format described in the
original project. Note: If your compiler doesn’t support variable-length arrays,
declare the array in main to be 99 x 99 instead of n x n and use the following
prototypes instead: void create_magic_square(int n, char magic_square[99] [99]);
void print_magic_square(int n, char magic_square[99] [99]);
*/
#include <stdio.h>

void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);

int main(void) {
  int n;

  printf("This program creates a magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99.\n");
  printf("Enter size of magic square: ");
  scanf("%d", &n);
  char magic_square[n][n];

  create_magic_square(n, magic_square);
  print_magic_square(n, magic_square);
}

void create_magic_square(int n, char magic_square[n][n]) {
  int row, col;
  int row_shift = 0;
  int col_shift = 0;

  // Initialize array to all zeros
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      magic_square[i][j] = 0;
    }
  }

  // Create magic square
  for (int i = (n * n); i > 0; i--) {
    row = (i + row_shift) % n;
    col = ((n * n - i) + (n / 2) + col_shift) % n;

    if (magic_square[row][col] != 0) {
      row_shift += 2;
      col_shift -= 1;
      row = (i + row_shift) % n;
      col = ((n * n - i) + (n / 2) + col_shift) % n;
    }

    magic_square[row][col] = (n * n - i) + 1;
  }
}

void print_magic_square(int n, char magic_square[n][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d\t", magic_square[i][j]);
    }
    printf("\n");
  }
}
