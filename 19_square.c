#include <stdint.h>
#include <stdio.h>

int main() {
  uint32_t size;
  printf("Enter square size: ");
  scanf("%u", &size);

  if (size == 1) {
    printf("#\n");
    return 0;
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i % (size - 1) == 0 || j % (size - 1) == 0)
        printf("#");
      else
        printf(" ");
      if (j == size - 1)
        printf("\n");
    }
  }
}
