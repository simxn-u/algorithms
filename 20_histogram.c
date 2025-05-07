#include <stdint.h>
#include <stdio.h>

#define MAXNUMBER 9

int main() {
  uint32_t numberCount;
  printf("Enter the number of numbers: ");
  scanf("%u", &numberCount);

  uint32_t numbers[MAXNUMBER + 1] = {0};
  for (int i = 0; i < numberCount; i++) {
    uint32_t input;
    scanf("%u", &input);
    numbers[input]++;
  }
  printf("----------------\n");
  for (int i = 1; i <= MAXNUMBER; i++) {
    printf("%d: ", i);
    while (numbers[i] > 0) {
      printf("*");
      numbers[i]--;
    }
    printf("\n");
  }
}
