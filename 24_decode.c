#include <stdint.h>
#include <stdio.h>

// Input: CiaonmdGe

int main() {
  char str[10];
  scanf("%s", str);

  int pos = 0;
  char arr[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      arr[i][j] = str[pos++];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c", arr[j][i]);
    }
  }
  printf("\n");
}
