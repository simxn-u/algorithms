#include <stdio.h>
#include <stdlib.h>

#define MAXNUMBER 9

int main() {
  uint32_t numberCount;
  printf("Enter the number of numbers: ");
  scanf("%u", &numberCount);

  int32_t numbers[MAXNUMBER + 1] = {0};
  for (int i = 0; i < numberCount; i++) {
    uint32_t number;
    scanf("%d", &number);
    numbers[number]++;
  }

  for (int i = MAXNUMBER; i >= 0; i--) {

    while (numbers[i] > 0) {
      printf("%d", i);
      numbers[i]--;
    }
  }
  printf("\n");
}
