/*
Write a program that generates a “random walk” across a 10 x 10 array. The array
will con¬ tain characters (all ' . ' initially). The program must randomly
“walk” from element to ele¬ ment, always going up. down, left, or right by one
element. The elements visited by the program will be labeled with the letters A
through Z. in the order visited. Here's an example A. of the desired output:
A . . . . . . . . .
B C D . . . . . . .
. F E . . . . . . .
H G . . . . . . . .
I . . . . . . . . .
J . . . . . . . Z .
K . . R S T U V Y .
L M P Q . . . W X .
. N O . . . . . . .
. . . . . . . . . .
Hint: Use the srand and rand functions (see deal.c) to generate random numbers.
After generating a number, look at its remainder when divided by 4. There are
four possible values for the remainder—0. 1.2, and 3—indicating the direction of
the next move. Before performing a move, cheek that (a) it won't go outside the
array, and (b) it doesn’t take us to an element that already has a letter
assigned. If either condition is violated, try moving in another direction. If
all four directions are blocked, the program must terminate. Here's an example
of premature termination:
A B G H I . . . . .
. C F . J K . . . .
. D E . M L . . . .
. . . . N O . . . .
. . W X Y P Q . . .
. . V U T S R . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
Y is blocked on all four sides, so there’s no place to put Z.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main(void) {
  char arr[ROWS][COLS];
  bool blocked = false;
  int direction;
  srand((unsigned)time(NULL));

  // Initialize arr with '.'
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      arr[i][j] = '.';
    }
  }

  // Generate random starting position
  int i = rand() % ROWS;
  int j = rand() % COLS;
  char character = 'A';
  arr[i][j] = character;

  int count = 0;
  while (!blocked && character < 'Z') {
    direction = rand() % 4;

    // If all 4 directions don't work then we're blocked!
    while (count < 4) {
      if (direction == 0) { // Up
        if (i - 1 >= 0 && arr[i - 1][j] == '.') {
          i--;
          character++;
          arr[i][j] = character;
          count = 0;
          break;
        }
      } else if (direction == 1) { // Right
        if (j + 1 < COLS && arr[i][j + 1] == '.') {
          j++;
          character++;
          arr[i][j] = character;
          count = 0;
          break;
        }
      } else if (direction == 2) { // Down
        if (i + 1 < ROWS && arr[i + 1][j] == '.') {
          i++;
          character++;
          arr[i][j] = character;
          count = 0;
          break;
        }
      } else if (direction == 3) { // Left
        if (j - 1 >= 0 && arr[i][j - 1] == '.') {
          j--;
          character++;
          arr[i][j] = character;
          count = 0;
          break;
        }
      }
      direction = (direction + 1) % 4;
      count++;
    }

    if (count >= 4) {
      blocked = true;
    }
  }

  // Print arr
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      putchar(arr[i][j]);
    }
    putchar('\n');
  }
  return 0;
}
