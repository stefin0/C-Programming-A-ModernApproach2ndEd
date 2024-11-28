/*
6. Write a function that computes the value of the following polynomial:
3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6
Write a program that asks the user to enter a value for x, calls the function to
compute the value of the polynomial, and then displays the value returned by the
function
*/
#include <math.h>
#include <stdio.h>

double evaluate_polynomial(double x);

int main(void) {
  double x;

  printf("Enter a value for x: ");
  scanf("%lf", &x);

  printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 = %lf\n", evaluate_polynomial(x));

  return 0;
}

double evaluate_polynomial(double x) {
  return 3 * pow(x, 5) + 2 * pow(x, 4) - 5 * pow(x, 3) - pow(x, 2) + 7 * x - 6;
}
