/*
Write a program that evaluates an expression:
Enter an expression: 1+2.5*3
Value of expression: 10.5
The operands in the expression are floating-point numbers; the operators are +,
-, *, and /. The expression is evaluated from left to right (no operator takes
precedence over any other operator).
*/

#include <stdio.h>

int main(void) {
  float value = 0.0, num;
  char sign = '+';

  printf("Enter an expression: ");

  while (1) {
    scanf("%f", &num);

    switch (sign) {
    case '+':
      value += num;
      break;
    case '-':
      value -= num;
      break;
    case '*':
      value *= num;
      break;
    case '/':
      value /= num;
      break;
    }

    // Skip whitespace
    while ((sign = getchar()) == ' ');

    if (sign != '+' && sign != '-' && sign != '*' && sign != '/') {
      break;
    }
  }

  printf("Value of expression: %.2f", value);

  return 0;
}
