#include <stdio.h>

int main(void) {
  int num;

  printf("Enter numerical grade: ");
  scanf("%d", &num);

  int tens = num / 10;

  printf("Letter grade: ");
  switch (tens) {
    case 10: case 9:
      printf("A");
      break;
    case 8:
      printf("B");
      break;
    case 7:
      printf("C");
      break;
    case 6:
      printf("D");
      break;
    case 5: case 4: case 3: case 2: case 1:
      printf("F");
      break;
    default: 
      printf("Illegal grade");
  }

  return 0;
}
