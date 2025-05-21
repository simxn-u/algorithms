#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 256

int main() {
  char caracter;
  printf("Enter a char: ");
  scanf("%c\n", &caracter);

  char input[MAXLEN];
  fgets(input, MAXLEN, stdin);
  uint32_t len = strlen(input);
  input[len - 1] = '\0';

  char lastChar;
  uint32_t count = 0;
  for (int i = 0; i < len; i++) {
    if (input[i] == caracter) {
      count++;
    } else {
      if (count != 0) {
        printf("%d", count);
        count = 0;
      }
      printf("%c", input[i]);
    }
  }
}
