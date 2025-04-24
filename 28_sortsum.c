#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUMBER 10
#define MAXLENGTH 100

int main() {
  uint32_t numbers[MAXNUMBER] = {0};
  char input[MAXLENGTH];
  fgets(input, MAXLENGTH, stdin);
  uint32_t len = strlen(input) - 1;
  input[strlen(input) - 1] = '\0';

  for (int i = 0; i < len; i++) {
    if (isdigit(input[i])) {
      numbers[input[i] - '0']++;
    }
  }

  for (int i = 0; i < len; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < MAXLENGTH; j++) {
        if (numbers[j] > 0) {
          printf("%d", j);
          numbers[j]--;
          break;
        }
      }
    } else {
      printf("+");
    }
  }
}
