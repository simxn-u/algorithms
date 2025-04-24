#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  uint32_t gridSize;
  printf("Enter the size of the grid: ");
  scanf("%d", &gridSize);

  char **grid = malloc(gridSize * sizeof(char *));
  for (int i = 0; i < gridSize; i++) {
    grid[i] = malloc(gridSize * sizeof(char));
  }
  for (int i = 0; i < gridSize; i++) {
    getchar();
    for (int j = 0; j < gridSize; j++) {
      grid[i][j] = getchar();
    }
  }

  uint32_t count = 0;
  char last = grid[0][0];
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridSize; j++) {
      if (grid[i][j] == last) {
        count++;
      } else {
        if (count > 1) {
          printf("%d%c", count, last);
        } else {
          printf("%c", last);
        }
        count = 1;
      }
      last = grid[i][j];
    }
  }
  if (count > 1) {
    printf("%d%c\n", count, last);
  } else {
    printf("%c\n", last);
  }

  for (int i = 0; i < gridSize; i++) {
    free(grid[i]);
  }
  free(grid);
}
