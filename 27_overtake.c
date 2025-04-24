#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define LENGTH 3
#define WIDTH 2

int main() {
  char street[LENGTH][WIDTH];
  for (int i = 0; i < LENGTH; i++) {
    for (int j = 0; j < WIDTH; j++) {
      street[i][j] = getchar();
    }
    getchar();
  }

  uint32_t carpos;
  for (int i = 0; i < LENGTH; i++) {
    if (street[i][0] != '|') {
      carpos = i;
      break;
    }
  }

  bool safe = true;
  if (street[carpos][1] == street[carpos][0])
    safe = false;
  if (street[carpos - 1][1] < street[carpos][0])
    safe = false;
  if (street[carpos + 1][1] > street[carpos][0])
    safe = false;

  safe ? printf("safe\n") : printf("unsafe\n");
}
