#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool isQuadratic(int32_t n) {
  int32_t root = sqrt(n);
  return root * root == n;
}

int main() {

  int32_t bot, top;
  printf("Enter the lower bound: ");
  scanf("%d", &bot);
  printf("Enter the upper bound: ");
  scanf("%d", &top);

  uint32_t count = 0;
  for (uint32_t i = bot; i <= top; i++) {
    if (isQuadratic(i))
      count++;
  }

  printf("%d\n", count);
}
