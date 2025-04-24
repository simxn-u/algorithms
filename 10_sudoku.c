#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#define SIZE 9

int main() {
  char sudoku[SIZE + 1];
  printf("Enter sudoku string: ");
  scanf("%s", sudoku);

  uint32_t sumInput = 0, expectedSum = 0;
  for (int i = 0; i < SIZE; i++) {
    expectedSum += i + 1;
    if (isdigit(sudoku[i])) {
      sumInput += sudoku[i] - '0';
    }
  }
  uint32_t missingNumber = expectedSum - sumInput;
  printf("%d\n", missingNumber);
}
