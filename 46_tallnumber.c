#include <stdint.h>
#include <stdio.h>

int main() {
  uint32_t input;
  printf("Enter number to check: ");
  scanf("%d", &input);

  uint32_t lastDigit = 9;
  for (int i = 0; input != 0; i++) {
    uint32_t digit = input % 10;
    if (digit > lastDigit) {
      printf("No\n");
      return 0;
    }
    lastDigit = digit;
    input /= 10;
  }
  printf("Yes\n");
}
