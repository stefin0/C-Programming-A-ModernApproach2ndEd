/*
Write a program that counts the number of vowels (a, e, i, o, and u) in a sentence:
Enter a sentence: And that's the way it is.
Your sentence contains 6 vowels.
*/
#include <ctype.h>
#include <stdio.h>
#define NUM_VOWELS ((int)(sizeof(vowels) / sizeof(vowels[0])))

int main(void) {
  char c;
  char vowels[] = {'a', 'e', 'i', 'o', 'u'};
  int count = 0;

  printf("Enter a sentence: ");
  while ((c = getchar()) != '\n') {
    for (int i = 0; i < NUM_VOWELS; ++i) {
      if (tolower(c) == vowels[i]) {
        count++;
        break;
      }
    }
  }

  printf("Your sentence contains %d vowels.", count);

  return 0;
}
