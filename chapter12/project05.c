/*
5. Modify Programming Project 14 from Chapter 8 so that it uses a pointer
instead of an integer to keep track of the current position in the array that
contains the sentence.
*/
#include <stdio.h>

#define SIZE 100

int main(void) {
  char sentence[SIZE];
  char terminator = '\0';

  printf("Enter a sentence: ");
  char c;
  char* position = sentence;
  while ((c = getchar()) != '\n' && position < (sentence + SIZE - 1)) {
    *position++ = c;
    if (c == '.' || c == '?' || c == '!') {
      terminator = c;
      break;
    }
  }
  if (terminator == '\0') {
    terminator = '.';
  }
  *position = '\0';

  printf("Reversal of sentence: ");
  char* right = position - 1;
  for (char* left = right; left >= sentence; left--) {
    // Reached beginning of the word
    if (*left == ' ' || left <= sentence) {
      // Print the word
      for (char* j = left; j < right; j++) {
        // Skip whitespace
        while (*j == ' ') {
          j++;
        }
        printf("%c", *j);
      }
      // Add space after every word
      if (left > sentence) {
        printf(" ");
      }
      right = left;
    }
  }
  printf("%c\n", terminator);

  return 0;
}
