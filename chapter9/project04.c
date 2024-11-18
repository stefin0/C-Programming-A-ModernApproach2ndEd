/*
4. Modify Programming Project 16 from Chapter 8 so that it includes the
following functions:
void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);
main will call read_word twice, once for each of the two words entered by the
user. As it reads a word. read_word will use the letters in the word to update
the counts array, as described in the original project, (main will declare two
arrays, one for each word. These arrays are used to track how many times each
letter occurs in the words.) main will then call equal_array, passing it the two
arrays, equalarray will return true if the elements in the two arrays are
identical (indicating that the words are anagrams) and false otherwise.
*/
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void) {
  int counts1[26] = {0};
  int counts2[26] = {0};

  printf("Enter first word: ");
  read_word(counts1);

  printf("Enter second word: ");
  read_word(counts2);

  printf("The words are ");
  if (equal_array(counts1, counts2)) {
    printf("anagrams.");
  } else {
    printf("not anagrams.");
  }

  return 0;
}

void read_word(int counts[26]) {
  char c;

  while ((c = getchar()) != '\n') {
    c = tolower(c);

    if (isalpha(c)) {
      counts[c - 'a']++;
    }
  }
}

bool equal_array(int counts1[26], int counts2[26]) {
  int isAnagram = true;

  for (int i = 0; i < 26; i++) {
    if (counts1[i] != counts2[i]) {
      isAnagram = false;
      break;
    }
  }

  return isAnagram;
}
