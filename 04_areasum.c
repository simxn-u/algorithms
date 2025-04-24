#include <stdio.h>
#include <stdlib.h>

int main() {
  uint32_t numberCount;
  printf("Enter the number of numbers: ");
  scanf("%u", &numberCount);

  int32_t *numbers = malloc(numberCount * sizeof(int32_t));
  for (int i = 0; i < numberCount; i++) {
    scanf("%d", &numbers[i]);
  }

  uint32_t rangesCount;
  printf("Enter the number of ranges: ");
  scanf("%u", &rangesCount);

  int32_t *ranges = malloc(rangesCount * 2 * sizeof(int32_t));
  for (int i = 0; i < rangesCount; i++) {
    scanf("%d %d", &ranges[i * 2], &ranges[i * 2 + 1]);
  }

  for (int i = 0; i < rangesCount; i++) {
    int32_t sum = 0;
    for (int j = ranges[i * 2]; j <= ranges[i * 2 + 1]; j++) {
      sum += numbers[j];
    }
    printf("%d\n", sum);
  }

  free(numbers);
}
