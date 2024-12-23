/*
3. Modify Programming Project 3 from Chapter 6 so that it includes the following
function: void reduce(int numerator, int denominator, int *reduced_numerator,
int *reduced_denominator);
numerator and denominator are the numerator and denominator of a fraction,
reduced numerator and reduced denominator are pointers to variables in which the
function will store the numerator and denominator ofthe fraction once it has
been reduced to lowest terms.
*/
#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator,
            int *reduced_denominator);

int main(void) {
  int numerator, denominator, reduced_numerator, reduced_denominator;

  printf("Enter a fraction: ");
  scanf("%d/%d", &numerator, &denominator);

  reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);
  printf("In lowest terms: %d/%d\n", reduced_numerator, reduced_denominator);

  return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator,
            int *reduced_denominator) {
  int m = numerator;
  int n = denominator;
  while (n != 0) {
    int remainder = m % n;
    m = n;
    n = remainder;
  }
  *reduced_numerator = numerator / m;
  *reduced_denominator = denominator / m;
}
