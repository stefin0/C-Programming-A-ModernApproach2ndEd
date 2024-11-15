/*
Write a program that calculates the average word length for a sentence:
Enter a sentence: It was deja vu all over again.
Average word length: 3.4
For simplicity, your program should consider a punctuation mark to be part of
the word to which it is attached. Display the average word length to one decimal
place.
*/
#include <ctype.h>
#include <stdio.h>

int main(void) {
  // Average Word Length
  float awl = 0.0;
  char c;
  int numChars = 0, numWords = 0;
  int inWord = 0;

  printf("Enter a sentence: ");

  /*
  To calculate the average word length for a sentence you need
  to sum all the letters for each word, then divide by the
  number of words.
  */
  while ((c = getchar()) != '\n') {
    if (!isspace(c)) {
      numChars++;

      if (!inWord) {
        numWords++;
        inWord = 1;
      }
    } else {
      inWord = 0;
    }
  }

  awl = (float)numChars / numWords;
  printf("Average word length: ");
  if (numWords == 0) {
    printf("0");
  } else {
    printf("%.1f", awl);
  }
  return 0;
}
