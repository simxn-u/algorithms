#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LETTERS 26

typedef struct {
  char key[101];
  uint32_t value;
  bool used;
} map;

int main() {
  uint32_t count;
  scanf("%u", &count);

  map maps[LETTERS] = {0};

  for (uint32_t i = 0; i < count; i++) {
    char key[101];
    uint32_t value;
    scanf("%s %u", key, &value);

    int index = key[0] - 'a';
    maps[index].value = value;
    strcpy(maps[index].key, key);
    maps[index].used = 1;
  }

  for (int i = 0; i < LETTERS; i++) {
    if (maps[i].used) {
      printf("%c: %s=%u\n", 'a' + i, maps[i].key, maps[i].value);
    }
  }

  return 0;
}
