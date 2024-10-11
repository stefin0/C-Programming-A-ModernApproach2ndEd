#include <ctype.h>
#include <stdio.h>

int main(void) {
  char phone_num[15];
  char c;
  int i = 0;

  // Ask the user to enter phone number.
  printf("Enter phone number: ");

  // For each character, store in phone_num[].
  while ((c = getchar()) != '\n' && i < 14) {
    switch (toupper(c)) {
    case 'A':
    case 'B':
    case 'C':
      c = '2';
      break;
    case 'D':
    case 'E':
    case 'F':
      c = '3';
      break;
    case 'G':
    case 'H':
    case 'I':
      c = '4';
      break;
    case 'J':
    case 'K':
    case 'L':
      c = '5';
      break;
    case 'M':
    case 'N':
    case 'O':
      c = '6';
      break;
    case 'P':
    case 'R':
    case 'S':
      c = '7';
      break;
    case 'T':
    case 'U':
    case 'V':
      c = '8';
      break;
    case 'W':
    case 'X':
    case 'Y':
      c = '9';
      break;
    default:
      break;
    }
    phone_num[i++] = c;
  }
  // End of phone_num
  phone_num[i] = '\0';

  printf("In numeric form: %s", phone_num);

  return 0;
}
