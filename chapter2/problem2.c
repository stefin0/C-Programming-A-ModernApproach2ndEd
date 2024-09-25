#include <stdio.h>

int main(void)
{
  float radius;
  printf("Radius: ");
  scanf("%f", &radius);
  float volume = 4.0f / 3.0f * 3.14 * radius * radius * radius;
  printf("Volume = %f", volume);
}
