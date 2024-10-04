#include <ctype.h>
#include <stdio.h>

int main(void) {
  char c;
  int value = 0;

  printf("Enter a word: ");
  c = getchar();
  while (c != '\n') {
    c = toupper(c);
    switch (c) {
    case 'A':
    case 'E':
    case 'I':
    case 'L':
    case 'N':
    case 'O':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
      value += 1;
      break;
    case 'D':
    case 'G':
      value += 2;
      break;
    case 'B':
    case 'C':
    case 'M':
    case 'P':
      value += 3;
      break;
    case 'F':
    case 'H':
    case 'V':
    case 'W':
    case 'Y':
      value += 4;
      break;
    case 'K':
      value += 5;
      break;
    case 'J':
    case 'X':
      value += 6;
      break;
    case 'Q':
    case 'Z':
      value += 7;
      break;
    default:
      value += 0;
    }
    c = getchar();
  }

  printf("Scrabble value: %d", value);

  return 0;
}
