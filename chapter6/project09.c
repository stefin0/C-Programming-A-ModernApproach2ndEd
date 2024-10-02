#include <stdio.h>

int main() {
  float loan;
  float interest_rate;
  float monthly_payment;
  float num_payments;

  printf("Enter amount of loan: ");
  scanf("%f", &loan);

  printf("Enter interest rate: ");
  scanf("%f", &interest_rate);
  interest_rate = (interest_rate / 100) / 12;

  printf("Enter monthly payment: ");
  scanf("%f", &monthly_payment);

  printf("Enter number of payments: ");
  scanf("%f", &num_payments);

  for (int i = 0; i < num_payments; i++) {
    loan = (loan - monthly_payment) + (loan * interest_rate);
    printf("Balance remaining after %d payment(s): %.2f\n", i + 1, loan);
  }

  return 0;
}
