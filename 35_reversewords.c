#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1024

int main() {
  char input[MAXLEN];
  printf("Enter a string: ");
  fgets(input, MAXLEN, stdin);
  input[strlen(input) - 1] = '\0';

  char words[MAXLEN][MAXLEN];
  char *token = strtok(input, " ");
  uint32_t pos = 0;
  while (token != NULL) {
    strcpy(words[pos++], token);
    token = strtok(NULL, " ");
  }
  for (int i = pos - 1; i >= 0; i--) {
    printf("%s ", words[i]);
  }
  printf("\n");
}
