#include <stdint.h>
#include <stdio.h>

void getPyramidHeight(int32_t *blocks, uint32_t *row) {
  uint32_t totalUsedBlocks = *row * (*row + 1) / 2;
  if (totalUsedBlocks <= *blocks) {
    (*row)++;
    getPyramidHeight(blocks, row);
    return;
  } else {
    (*row)--;
    *blocks -= *row * (*row + 1) / 2;
  }
}

int main() {
  int32_t blocks;
  printf("Input number of blocks: ");
  scanf(" %d", &blocks);

  uint32_t row = 1;
  getPyramidHeight(&blocks, &row);
  printf("%d %d\n", row, blocks);
}
