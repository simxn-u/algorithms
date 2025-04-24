#include <stdint.h>
#include <stdio.h>

int main() {
  uint32_t top;
  printf("Enter upper number: ");
  scanf("%d", &top);

  uint32_t sum = 0;
  for (int i = 2; i <= top; i += 2) {
    sum += i;
  }
  printf("%d\n", sum);
}
