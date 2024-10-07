#include <ctype.h>
#include <stdio.h>

int main(void) {
  char c;
  char message[100];

  // Get user input
  printf("Enter message: ");

  // Store each character of message in array
  c = getchar();
  int char_index = 0;
  while (c != '\n' && char_index < 99) {
    c = toupper(c);
    switch (c) {
    case 'A':
      c = '4';
      break;
    case 'B':
      c = '8';
      break;
    case 'E':
      c = '3';
      break;
    case 'I':
      c = '1';
      break;
    case 'O':
      c = '0';
      break;
    case 'S':
      c = '5';
      break;
    }
    message[char_index] = c;
    char_index++;
    c = getchar();
  }
  message[char_index] = '\0';

  printf("In B1FF-speak: %s!!!!!!!!!", message);

  return 0;
}
