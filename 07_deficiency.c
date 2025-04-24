#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t getDivisorSum(int32_t n) {
  int32_t sum = 0;
  for (int32_t i = 1; i <= n; i++) {
    if (n % i == 0)
      sum += i;
  }
  return sum;
}

int32_t getDeficiencySum(int32_t a, int32_t b) {
  int32_t totalDeficiency = 0;
  for (int32_t n = a; n <= b; n++) {
    int32_t divisorSum = getDivisorSum(n);
    int32_t doubleN = 2 * n;

    if (divisorSum < doubleN) {
      int32_t deficiency = doubleN - divisorSum;
      totalDeficiency += deficiency;
    }
  }
  return totalDeficiency;
}

int main() {
  uint32_t sectionCount;
  printf("Enter the number of sections: ");
  scanf("%u", &sectionCount);

  int32_t *sections = malloc(sectionCount * 2 * sizeof(int32_t));
  for (uint32_t i = 0; i < sectionCount; i++) {
    scanf("%d %d", &sections[2 * i], &sections[2 * i + 1]);
  }

  for (uint32_t i = 0; i < sectionCount; i++) {
    int32_t a = sections[2 * i];
    int32_t b = sections[2 * i + 1];
    int32_t result = getDeficiencySum(a, b);
    printf("%d\n", result);
  }

  free(sections);
  return 0;
}
