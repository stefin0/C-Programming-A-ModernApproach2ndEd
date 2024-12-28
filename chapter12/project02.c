/*
2. (a) Write a program that reads a message, then checks whether it’s a
palindrome (the letters in the message are the same from left to right as from
right to left):
Enter a message: He lived as a devil, eh?
Palindrome
Enter a message: Madam, I am Adam.
Not a palindrome
Ignore all characters that aren’t letters. Use integer variables to keep track
of positions in the array. (b) Revise the program to use pointers instead of
integers to keep track of positions in the array.
*/
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

bool is_palindrome(char string[], int length);

#define SIZE 100

int main(void) {
  char message[SIZE];
  char c;

  printf("Enter a message: ");
  int length = 0;
  while ((c = getchar()) != '\n' && length < SIZE - 1) {
    message[length++] = c;
  }
  message[length] = '\0';

  if (is_palindrome(message, length)) {
    printf("Palindrome\n");
  } else {
    printf("Not a palindrome\n");
  }

  return 0;
}

bool is_palindrome(char string[], int length) {
  char *left = string;
  char *right = &string[length - 1];

  while (left < right) {
    while (!isalnum(*left) && left < right) {
      left++;
    }

    while (!isalnum(*right) && right > left) {
      right--;
    }

    if (tolower(*left) != tolower(*right)) {
      return false;
    }

    left++;
    right--;
  }
  return true;
}
