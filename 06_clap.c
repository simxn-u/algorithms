#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool checkClap(uint32_t number) {
  if (number % 7 == 0)
    return true;
  uint32_t sum = 0;
  while (number > 0) {
    if (number % 10 == 7)
      return true;

    sum += number % 10;
    number /= 10;
  }
  if (sum % 7 == 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  uint32_t maxRounds;
  printf("Enter the number of rounds: ");
  scanf("%u", &maxRounds);

  for (int i = 1; i <= maxRounds; i++) {
    bool result = checkClap(i);
    if (result)
      printf("CLAP\n");
    else
      printf("%d\n", i);
  }
}
