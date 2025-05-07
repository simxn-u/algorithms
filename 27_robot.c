#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 512

typedef struct {
  char dir;
  char symbol;
} Commands;

Commands commands[] = {{'u', '^'}, {'d', 'v'}, {'l', '<'}, {'r', '>'}};

int main() {
  char input[MAXLEN];
  printf("Enter the path: ");
  fgets(input, MAXLEN, stdin);
  uint32_t len = strlen(input) - 1;
  input[len] = '\0';

  char *token = strtok(input, " ");
  while (token != NULL) {
    for (int i = 0; i < 4; i++) {
      if (token[0] == commands[i].dir) {
        printf("%c", commands[i].symbol);
        break;
      }
    }
    token = strtok(NULL, " ");
  }
}
