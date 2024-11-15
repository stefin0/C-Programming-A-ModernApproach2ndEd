/*
15.Write a program that computes the factorial of a positive integer:
Enter a positive integer: 6
Factorial of 6: 720
(a) Use a short variable to store the value of the factorial. What is the largest value of n
for which the program correctly prints the factorial of «?
(b) Repeat part (a), using an int variable instead.
(c) Repeat part (a), using a long variable instead.
(d) Repeat part (a), using a long long variable instead (if your compiler supports the
long long type).
(e) Repeat part (a), using a float variable instead.
(f) Repeat part (a), using a double variable instead.
(g) Repeat part (a), using a long double variable instead.
In cases (e)-(g). the program will display a close approximation of the factorial, not neces-
sarily the exact value.
*/
#include <stdio.h>

int main(void) {
  int num, fact = 1;

  printf("Enter a positive integer: ");
  scanf("%d", &num);

  printf("Factorial of %d: ", num);
  while (num > 0) {
    fact *= num;
    num--;
  }
  printf("%d", fact);

  return 0;
}
