/*
3. Modify Programming Project 9 from Chapter 8 so that it includes the following
functions:
void generate_random_walk(char walk[10] [10]);
void print_array(char walk[10] [10]);
main first calls generate_random_walk. which initializes the array to contain
'.' characters and then replaces some of these characters by the letters A
through Z, as described in the original project, main then calls print_array to
display the array on the screen.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

int main(void) {
  char walk[ROWS][COLS];

  generate_random_walk(walk);
  print_array(walk);

  return 0;
}

void generate_random_walk(char walk[10][10]) {
  bool blocked = false;
  int direction;
  srand((unsigned)time(NULL));

  // Initialize arr with '.'
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      walk[i][j] = '.';
    }
  }

  // Generate random starting position
  int i = rand() % ROWS;
  int j = rand() % COLS;
  char character = 'A';
  walk[i][j] = character;

  int count = 0;
  while (!blocked && character < 'Z') {
    direction = rand() % 4;

    // If all 4 directions don't work then we're blocked!
    while (count < 4) {
      if (direction == 0) { // Up
        if (i - 1 >= 0 && walk[i - 1][j] == '.') {
          i--;
          character++;
          walk[i][j] = character;
          count = 0;
          break;
        }
      } else if (direction == 1) { // Right
        if (j + 1 < COLS && walk[i][j + 1] == '.') {
          j++;
          character++;
          walk[i][j] = character;
          count = 0;
          break;
        }
      } else if (direction == 2) { // Down
        if (i + 1 < ROWS && walk[i + 1][j] == '.') {
          i++;
          character++;
          walk[i][j] = character;
          count = 0;
          break;
        }
      } else if (direction == 3) { // Left
        if (j - 1 >= 0 && walk[i][j - 1] == '.') {
          j--;
          character++;
          walk[i][j] = character;
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
}

void print_array(char walk[10][10]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      putchar(walk[i][j]);
    }
    putchar('\n');
  }
}
