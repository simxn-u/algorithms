#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 1024

int main() {
  char input[MAXLEN];
  printf("Enter a string: ");
  scanf("%s", input);

  uint32_t letters[26] = {0};

  for (int i = 0; i < strlen(input); i++) {
    if (input[i] >= 'a' && input[i] <= 'z') {
      letters[input[i] - 'a']++;
    } else if (input[i] >= 'A' && input[i] <= 'Z') {
      letters[input[i] - 'A']++;
    }
  }

  for (int i = 0; i < 26; i++) {
    if (letters[i] == 0) {
      printf("false\n");
      return 0;
    }
  }

  printf("true\n");
  return 0;
}
