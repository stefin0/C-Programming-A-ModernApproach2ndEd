/*
1. (a) Write a program that reads a message, then prints the reversal of the
message:
Enter a message: Don't get mad, get even.
Reversal is: .neve teg ,dam teg t'noD
Hint: Read the message one character at a time (using getchar) and
store the characters in an array. Stop reading when the array is full or the
character read is '\n'. (b) Revise the program to use a pointer instead of an
integer to keep track of the current position in the array.
*/
#include <stdio.h>

#define SIZE 100

int main(void) {
  char message[SIZE];
  char c;
  char *p;

  printf("Enter a message: ");
  int length = 0;
  while ((c = getchar()) != '\n' && length < SIZE - 1) {
    message[length++] = c;
  }
  message[length] = '\0';

  printf("Reversal is: ");
  for (p = &message[length - 1]; p >= message; p--) {
    printf("%c", *p);
  }
  printf("\n");

  return 0;
}
