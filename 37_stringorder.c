#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 256

int main() {
  uint32_t n;
  printf("Enter length of string: ");
  scanf("%d\n", &n);

  char input[MAXLEN];
  fgets(input, MAXLEN, stdin);
  input[n] = '\0';

  uint32_t order[MAXLEN] = {0};
  for (int i = 0; i < n; i++) {
    scanf("%d", &order[i]);
  }

  for (int i = 0; i < n; i++) {
    printf("%c", input[order[i] - 1]);
  }
}
