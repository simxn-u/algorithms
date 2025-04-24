#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

uint32_t devide(char *input) {
  uint32_t letters = 0, numbers = 0;
  for (int i = 0; i < strlen(input); i++) {
    if (isdigit(input[i]))
      numbers++;
    else if (isalpha(input[i]))
      letters++;
  }
  return letters / numbers;
}

int main() {
  char input[100];
  printf("Enter sentence: ");
  scanf("%s", input);

  uint32_t result;
  result = devide(input);
  printf("%d\n", result);
}
