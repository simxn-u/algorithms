#include <stdint.h>
#include <stdio.h>

int main() {
  uint32_t carCount;
  printf("Enter number of cars: ");
  scanf("%d", &carCount);

  uint32_t timeTable[24] = {0};
  for (int i = 0; i < carCount; i++) {
    uint32_t entry, exit;
    scanf("%d%d", &entry, &exit);
    for (int j = entry; j < exit; j++) {
      timeTable[j]++;
    }
  }

  uint32_t notEmpty = 0;
  for (int i = 0; i < 24; i++) {
    if (timeTable[i] > 0) {
      notEmpty++;
    }
  }

  printf("%d\n", notEmpty);
}
