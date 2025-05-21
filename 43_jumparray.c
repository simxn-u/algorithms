#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define MAXLEN 300

int main() {
  uint32_t len;
  printf("Enter the length of the array: ");
  scanf("%d", &len);

  uint32_t arr[MAXLEN];
  for (int i = 0; i < len; i++) {
    uint32_t val;
    scanf("%d", &val);
    if (val >= len) {
      printf("Value %d is greater than the length of the array\n", val);
      return -1;
    }

    arr[i] = val;
  }

  uint32_t pos = 0;
  bool isBeginning = false;
  for (int i = 0; i < len; i++) {
    if (arr[pos] == 0) {
      isBeginning = true;
      break;
    }
    pos = arr[i];
  }
  isBeginning ? printf("true\n") : printf("false\n");
}
