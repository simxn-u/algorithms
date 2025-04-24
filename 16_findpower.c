#include <stdint.h>
#include <stdio.h>

int main() {
  uint32_t number, base;
  printf("Enter the number: ");
  scanf("%u", &number);
  printf("Enter the base: ");
  scanf("%u", &base);

  uint32_t value = base;
  uint32_t power = 0;
  while (1) {
    if (value > number)
      break;
    value *= base;
    power++;
  }
  printf("%u\n", power);
}
