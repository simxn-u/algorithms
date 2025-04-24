#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 256

int main() {
  char input[MAXLEN];
  printf("Enter a string: ");
  fgets(input, MAXLEN, stdin);
  input[strlen(input) - 1] = '\0';

  bool uppercase = false;
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      uppercase = true;
      continue;
    }

    if (uppercase) {
      printf("%c", toupper(input[i]));
      uppercase = false;
    } else {
      printf("%c", tolower(input[i]));
    }
  }
  printf("\n");
}
