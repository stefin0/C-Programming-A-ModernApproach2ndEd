/*
1. Write a program that asks the user to enter a series of integers (which it
stores in an array), then sorts the integers by calling the function
selection_sort. When given an array with n elements, selection_sort must do the
following:
1. Search the array to find the largest element, then move it to the last
position in the array.
2. Call itself recursively to sort the first n - 1 elements of the array.
*/
#include <stdio.h>
#define MAX_SIZE 10

void selection_sort(int arr_len, int arr[]);
void print_arr(int arr_len, int arr[]);

int main(void) {
  int arr[MAX_SIZE];
  int i = 0;
  int num;

  // Store input into arr
  printf("Enter up to %d integers (0 to quit): ", MAX_SIZE);
  while (i < MAX_SIZE) {
    scanf("%d", &num);
    if (num == 0) {
      break;
    }
    arr[i++] = num;
  }

  // i = length of arr
  selection_sort(i, arr);

  print_arr(i, arr);

  return 0;
}

void selection_sort(int arr_len, int arr[]) {
  // Base case:
  // array length is 1, or less than 1.
  if (arr_len <= 1) {
    return;
  }

  for (int i = 0; i < arr_len - 1; i++) {
    if (arr[i] > arr[arr_len - 1]) {
      // Swap the largest element with the last element
      // in the unsorted array.
      int temp = arr[arr_len - 1];
      arr[arr_len - 1] = arr[i];
      arr[i] = temp;
    }
  }

  selection_sort(arr_len - 1, arr);
}

void print_arr(int arr_len, int arr[]) {
  for (int i = 0; i < arr_len; i++) {
    printf("%d ", arr[i]);
  }
}
