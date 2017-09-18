#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[]) {
  // make sure there are two arguments
  if (argc != 2) {
    printf("You need to provide a number.\n");
    return 1;
  }

  // turn key into integer
  int k = atoi(argv[1]);

  // make sure k is non-negative
  if (k < 0) {
    printf("Number must be non-negative.\n");
    return 1;
  }

  // establish variable for plaintext
  string plain;

  // get plaintext from user
  printf("plaintext: ");
  plain = get_string();
  // get ready to print ciphertext
  printf("ciphertext: ");

  // loop through user's string input
  for (int i = 0; i < strlen(plain); i++) {
    // set starting variable for cipher output
    int cipher = 0;
    // if character is uppercase, convert to equivalent uppercase cipher using the alphabetical index
    if (isupper(plain[i])) {
      cipher = (((plain[i] + k) - 65) % 26) + 65;
      printf("%c", cipher);
    }
    // if character is lowercase, convert to equivalent lowercase cipher using the alphabetical index
    else if (islower(plain[i])) {
      cipher = (((plain[i] + k) - 97) % 26) + 97;
      printf("%c", cipher);
    }
    // otherwise just print the character
    else {
      printf("%c", plain[i]);
    }
  }

  // print new line and exit program
  printf("\n");
  return 0;
}
