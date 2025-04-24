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
    for (int j = 0; j < gridSize; j++) {
      scanf(" %c", &grid[i][j]);
    }
  }

  for (int i = 0; i < gridSize; i++) {
    printf("%c", grid[i][i]);
  }
  printf(" ");
  for (int i = 0; i < gridSize; i++) {
    printf("%c", grid[i][gridSize - i - 1]);
  }
  printf("\n");
}
