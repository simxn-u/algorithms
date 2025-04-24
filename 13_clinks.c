#include <stdint.h>
#include <stdio.h>

int main() {
  uint32_t peopleCount;
  printf("Enter the number of people: ");
  scanf("%u", &peopleCount);

  uint32_t clinks = peopleCount * (peopleCount - 1) / 2;
  printf("%u\n", clinks);
}
