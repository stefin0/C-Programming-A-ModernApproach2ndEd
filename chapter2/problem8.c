#include <stdio.h>

int main()
{
  float loan;
  float interest_rate;
  float monthly_payment;

  printf("Enter amount of loan: ");
  scanf("%f", &loan);

  printf("Enter interest rate: ");
  scanf("%f", &interest_rate);
  interest_rate = (interest_rate / 100) / 12;

  printf("Enter monthly payment: ");
  scanf("%f", &monthly_payment);

  loan = (loan - monthly_payment) + (loan * interest_rate);
  printf("Balance remaining after first payment: %.2f\n", loan);

  loan = (loan - monthly_payment) + (loan * interest_rate);
  printf("Balance remaining after first payment: %.2f\n", loan);

  loan = (loan - monthly_payment) + (loan * interest_rate);
  printf("Balance remaining after first payment: %.2f\n", loan);

  return 0;
}
