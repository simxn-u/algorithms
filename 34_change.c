#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[256];
  printf("Calculate return coins: ");
  getchar(); // remove $ sign
  scanf("%[^\n]", input);

  double amount = atof(input);
  double coins[] = {1, 0.25, 0.10, 0.05, 0.01};

  uint32_t count;

  for (int i = 0; i < 5; i++) {
    count = 0;
    while (amount >= coins[i]) {
      amount -= coins[i];
      count++;
    }
    printf("%d ", count);
  }
}
