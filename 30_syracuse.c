#include <stdint.h>
#include <stdio.h>

int main() {
  uint32_t number;
  printf("Enter a number: ");
  scanf("%u", &number);

  while (number != 1) {
    if (number % 2 == 0) {
      number /= 2;
    } else {
      number = 3 * number + 1;
    }
    printf("%u\n", number);
  }
}
