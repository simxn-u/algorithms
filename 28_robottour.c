#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 512

typedef struct {
  char *dir;
  char symbol;
} Commands;

Commands commands[] = {
    {"up", '^'}, {"down", 'v'}, {"left", '<'}, {"right", '>'}};

int main() {
  char input[MAXLEN];
  printf("Enter the path: ");
  fgets(input, MAXLEN, stdin);
  uint32_t len = strlen(input) - 1;
  input[len] = '\0';

  char *token = strtok(input, " ");
  while (token != NULL) {
    for (int i = 0; i < 4; i++) {
      if (strcmp(token, commands[i].dir) == 0) {
        int count = 1;
        char *next = strtok(NULL, " ");
        while (next != NULL && strcmp(next, commands[i].dir) == 0) {
          count++;
          next = strtok(NULL, " ");
        }
        if (count > 1)
          printf("%d", count);
        printf("%c", commands[i].symbol);
        token = next;
        goto nextToken;
      }
    }
    token = strtok(NULL, " ");
  nextToken:;
  }
}
