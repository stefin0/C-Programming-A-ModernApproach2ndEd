#include <stdio.h>

int main(void)
{
  int area, first, second;

  printf("Enter phone number [(xxx) xxx-xxxx]: ");
  scanf("(%d) %d-%d", &area, &first, &second);

  printf("You entered %d.%d.%d", area, first, second);
}
