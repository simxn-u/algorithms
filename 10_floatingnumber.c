#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void floatingNumber(uint32_t *number) {
  uint32_t val = *number;
  while (val != 0) {
    *number += val % 10;
    val /= 10;
  }
}

int main() {
  uint32_t nr1, nr2;
  scanf("%u %u", &nr1, &nr2);

  while (1) {
    if (nr1 == nr2)
      break;
    if (nr1 > nr2)
      floatingNumber(&nr2);
    else
      floatingNumber(&nr1);
  }
  printf("%u\n", nr1);
}
