/*
Write a program that reads a 5 x 5 array of integers and then prints the row
sums and the column sums:
Enter row 1: 8 3 9 0 10
Enter row 2: 3 5 17 1 1
Enter row 3: 2 8 6 23 1
Enter row 4: 15 7 3 2 9
Enter row 5: 6 14 2 6 0
Row totals: 30 27 40 36 28
Column totals: 34 37 37 32 21
*/
#include <stdio.h>

#define ARR_SIZE 5

int main(void) {
  int arr[ARR_SIZE][ARR_SIZE] = {0};
  int row_totals[ARR_SIZE] = {0};
  int column_totals[ARR_SIZE] = {0};

  for (int i = 0; i < ARR_SIZE; i++) {
    printf("Enter row %d: ", i+1);
    for (int j = 0; j < ARR_SIZE; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  for (int i = 0; i < ARR_SIZE; i++) {
    for (int j = 0; j < ARR_SIZE; j++) {
      row_totals[i] += arr[i][j];
      column_totals[j] += arr[i][j];
    }
  }

  printf("\nRow totals: ");
  for (int i = 0; i < ARR_SIZE; i++) {
    printf("%d ", row_totals[i]);
  }

  printf("\nColumn totals: ");
  for (int i = 0; i < ARR_SIZE; i++) {
    printf("%d ", column_totals[i]);
  }

  return 0;
}
