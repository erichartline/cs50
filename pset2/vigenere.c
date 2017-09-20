#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[]) {
  // make sure there are two arguments
  if (argc != 2) {
    printf("You need to provide a keyword.\n");
    return 1;
  }

  // establish variables
  string plain;
  string key = argv[1];

  // make sure keyword uses letters only
  for (int i = 0; i < strlen(key); i++) {
    if (!isalpha(key[i])) {
      printf("Alphabetical characters only please!\n");
      return 1;
    }
  }

  // get plaintext from user
  printf("plaintext: ");
  plain = get_string();
  // get ready to print ciphertext
  printf("ciphertext: ");

  // loop through user's string input
  for (int i = 0, j = 0; i < strlen(plain); i++) {
    // establish cipher variable
    int cipher = 0;
    // set counter for the length of the key, loops back to beginning after each go through
    j = j % strlen(key);

    // check if each character in plaintext is alphabetical and convert to appropriate case
    if (isalpha(plain[i])) {
      if (isupper(plain[i])) {
        if (isupper(key[j])) {
          cipher = (((plain[i] - 65) + (key[j] - 65)) % 26) + 65;
          printf("%c", cipher);
        }
        else {
          cipher = (((plain[i] - 65) + (key[j] - 97)) % 26) + 65;
          printf("%c", cipher);
        }
      }
      else if (islower(plain[i])) {
        if (islower(key[j])) {
          cipher = (((plain[i] - 97) + (key[j] - 97)) % 26) + 97;
          printf("%c", cipher);
        }
        else {
          cipher = (((plain[i] - 97) + (key[j] - 65)) % 26) + 97;
          printf("%c", cipher);
        }
      }
      // increase key length counter
      j++;
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
