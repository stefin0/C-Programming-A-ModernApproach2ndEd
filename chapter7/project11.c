/*
Write a program that takes a first name and last name entered by the user and displays the
last name, a comma, and the first initial, followed by a period:
Enter a first and last name: Lloyd Fosdick
Fosdick, L.
The user’s input may contain extra spaces before the first name, between the first and last
names, and after the last name.
*/
#include <stdio.h>
#define LNAME_SIZE 20

int main(void) {
  char fname;
  char lname[LNAME_SIZE];
  char c;
  int i = 0;

  printf("Enter a first and last name: ");
  scanf(" %c", &fname);

  while ((c = getchar()) != ' ' && c != '\n');

  while ((c = getchar()) == ' ');

  do {
    lname[i++] = c;
  } while ((c = getchar()) != ' ' && c != '\n' && i < LNAME_SIZE);

  lname[i] = '\0';

  printf("%s, %c.", lname, fname);

  return 0;
}
