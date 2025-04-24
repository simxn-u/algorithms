#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void sortTriplets(int32_t *triplets, uint32_t tripleCount) {
  for (int i = 0; i < tripleCount; i++) {
    int32_t a = triplets[i * 3];
    int32_t b = triplets[i * 3 + 1];
    int32_t c = triplets[i * 3 + 2];

    if (a > b) {
      int32_t temp = a;
      a = b;
      b = temp;
    }
    if (a > c) {
      int32_t temp = a;
      a = c;
      c = temp;
    }
    if (b > c) {
      int32_t temp = b;
      b = c;
      c = temp;
    }

    triplets[i * 3] = a;
    triplets[i * 3 + 1] = b;
    triplets[i * 3 + 2] = c;
  }
}

int main() {
  uint32_t tripleCount;
  printf("Enter the number of triples: ");
  scanf("%u", &tripleCount);

  int32_t *triplets = malloc(tripleCount * 3 * sizeof(int32_t));
  for (int i = 0; i < tripleCount; i++) {
    scanf("%d %d %d", &triplets[i * 3], &triplets[i * 3 + 1],
          &triplets[i * 3 + 2]);
  }

  sortTriplets(triplets, tripleCount);

  for (int i = 0; i < tripleCount; i++) {
    printf("%d\n", triplets[i * 3 + 1]);
  }
}
