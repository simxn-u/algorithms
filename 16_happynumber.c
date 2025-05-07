#include <ctype.h>
#include <stdint.h>
#include <stdio.h>

#define MAXTRIES 100
#define MAXLEN 256

int main() {
  char input[MAXLEN];
  printf("Enter the number: ");
  scanf("%s", input);

  for (int i = 0; i < MAXTRIES; i++) {
    uint32_t sum = 0;
    for (int j = 0; input[j] != '\0'; j++) {
      if (isnumber(input[j])) {
        sum += (input[j] - '0') * (input[j] - '0');
      }
    }
    if (sum == 1) {
      printf("Happy number\n");
      return 0;
    } else {
      sprintf(input, "%d", sum);
    }
  }

  printf("Not a happy number\n");
  return -1;
}
