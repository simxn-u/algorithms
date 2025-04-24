#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  uint32_t fruitCount;
  printf("Enter the number of fruits: ");
  scanf("%u", &fruitCount);

  char type;
  uint32_t count;
  printf("Enter the type and count of each fruit: ");
  scanf(" %c %u", &type, &count);
  getchar();

  char *fruits;
  fruits = malloc(fruitCount * sizeof(char) * 10);
  fgets(fruits, fruitCount * 10, stdin);
  fruits[fruitCount * 10 - 1] = '\0';

  uint32_t juiceCount;
  for (int i = 0; i < fruitCount; i++) {
    uint32_t juice = 0;
    for (int i = 0; i < fruitCount * 10; i++) {
      if (fruits[i] == type) {
        juice++;
      } else {
        continue;
      }
    }
    juiceCount = juice / count;
  }
  printf("%u\n", juiceCount);
}
