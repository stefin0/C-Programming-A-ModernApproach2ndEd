#include <ctype.h>
#include <stdio.h>

int main(void) {
  char c;

  printf("Enter phone number: ");
  c = getchar();
  while (c != '\n') {
    c = toupper(c);
    if (c == 'A' || c == 'B' || c == 'C') {
      putchar('2');
    } else {
      putchar(c);
    }
    c = getchar();
  }
}
