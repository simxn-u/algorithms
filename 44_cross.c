#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  uint32_t length, width;
  printf("Width and length of the array: ");
  scanf("%d %d\n", &width, &length);

  uint32_t arr[length][width];
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < width; j++) {
      getchar() == 'X' ? (arr[i][j] = 1) : (arr[i][j] = 0);
    }
    getchar();
  }

  uint32_t crossCount = 0;
  for (int i = 1; i < length - 1; i++) {
    for (int j = 1; j < width - 1; j++) {
      if (arr[i][j] == 1) {
        if (arr[i - 1][j] == 1 && arr[i + 1][j] == 1 && arr[i][j - 1] == 1 &&
            arr[i][j + 1] == 1) {
          crossCount++;
        }
      }
    }
  }
  printf("%d\n", crossCount);
}
