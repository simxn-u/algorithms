#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 256

int main() {
  char input[MAXLEN];
  printf("Enter input string: ");
  fgets(input, MAXLEN, stdin);
  uint32_t len = strlen(input);
  input[len - 1] = '\0';

  uint32_t chars[MAXLEN][2] = {0};
  for (int i = 0; i < len; i++) {
    uint32_t check = input[i];
    uint32_t count = 1;
    for (int j = 0; j < i; j++) {
      if (chars[j][0] == check) {
        count++;
      }
    }
    chars[i][0] = check;
    chars[i][1] = count;
  }

  for (int i = 0; i < len; i++) {
    for (int j = 0; j < chars[i][1]; j++) {
      printf("%c", chars[i][0]);
    }
  }
}
