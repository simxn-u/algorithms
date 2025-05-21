#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 512

typedef struct {
  char dir;
  int8_t dirX;
  int8_t dirY;
} Commands;

Commands commands[] = {{'^', -1, 0}, {'<', 0, -1}, {'>', 0, 1}, {'v', 1, 0}};

int main() {
  char input[MAXLEN];
  printf("Enter the path: ");
  fgets(input, MAXLEN, stdin);
  uint32_t len = strlen(input) - 1;
  input[len] = '\0';

  uint8_t grid[MAXLEN * 2][MAXLEN * 2] = {0};
  uint8_t x = (uint8_t)MAXLEN, y = (uint8_t)MAXLEN;
  grid[x][y] = 1;

  for (uint32_t i = 0; i < len; i++) {
    char c = input[i];
    for (int j = 0; j < 4; j++) {
      if (c == commands[j].dir) {
        grid[x += commands[j].dirX][y += commands[j].dirY]++;
        break;
      }
    }
  }

  uint8_t maxVisits = 0;
  for (int i = 0; i < MAXLEN * 2; i++) {
    for (int j = 0; j < MAXLEN * 2; j++) {
      if (grid[i][j] > maxVisits) {
        maxVisits = grid[i][j];
      }
    }
  }
  printf("Max visits: %d\n", maxVisits);
}
