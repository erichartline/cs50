#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void) {
  long long cc = 0;

  do {
    printf("Number: ");
    cc = get_long_long();
  }
  while (cc <= 0);

  // int digits = 0;
  // long long fullNumber = cc;
  //
  // while (fullNumber > 0) {
  //   fullNumber /= 10;
  //   digits++;
  // }
  //
  // if (digits != 15 || digits != 16 || digits != 13) {
  //   printf("INVALID\n");
  // }

  int firstDigit = 0;
  int lastDigit = cc % 10;
  int product = 0;
  int firstSum = 0;
  int sum = 0;

  // loop to multiply every other digit
  for (int i = 0; i < cc; i++) {
    int secondToLastDigit = ((cc / 10) % 10);
    if (i % 2 != 0) {
      product = secondToLastDigit * 2;
      firstSum += product;
    }
    return firstSum;
  }

  // loop to add digits not multiplied by 2
  for (int j = 0; j < cc; j++) {
    if (j % 2 == 0) {
      sum += cc % 10;
    }
    cc /= 10;
    return sum;
  }

  // need to determine firstDigit

  if (lastDigit == 0) {
    if (firstDigit == 4) {
      printf("VISA\n");
    } else if (firstDigit == 34 || firstDigit == 37) {
      printf("AMEX\n");
    } else if (firstDigit == 51 || firstDigit == 52 || firstDigit == 53 || firstDigit == 54 || firstDigit == 55) {
      printf("MASTERCARD\n");
    }
  } else {
    printf("INVALID\n");
  }
}
