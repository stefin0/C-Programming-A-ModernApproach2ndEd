/*
14. Write a program that reverses the words in a sentence:
Enter a sentence: you can cage a swallow can't you?
Reversal of sentence: you can't swallow a cage can you?
Hint: Use a loop to read the characters one by one and store them in a
one-dimensional char array. Have the loop stop at a period, question mark, or
exclamation point (the "terminating character"), which is saved in a separate
char variable. Then use a second loop to search backward through the array for
the beginning of the last word. Print the last word, then search backward for
the next-to-last word. Repeat until the beginning of the array is reached.
Finally, print the terminating character.
*/
#include <stdio.h>

#define SIZE 100

int main(void) {
  char sentence[SIZE];
  char terminator = '\0';

  printf("Enter a sentence: ");
  char c;
  int length = 0;
  while ((c = getchar()) != '\n' && length < SIZE - 1) {
    sentence[length++] = c;
    if (c == '.' || c == '?' || c == '!') {
      terminator = c;
      break;
    }
  }
  if (terminator == '\0') {
    terminator = '.';
  }
  sentence[length] = '\0';

  printf("Reversal of sentence: ");
  int right = length - 1;
  for (int left = right; left >= 0; left--) {
    // Reached beginning of the word
    if (sentence[left] == ' ' || left <= 0) {
      // Print the word
      for (int j = left; j < right; j++) {
        // Skip whitespace
        while (sentence[j] == ' ') {
          j++;
        }
        printf("%c", sentence[j]);
      }
      // Add space after every word
      if (left > 0) {
        printf(" ");
      }
      right = left;
    }
  }
  printf("%c\n", terminator);

  return 0;
}
