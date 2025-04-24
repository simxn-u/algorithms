#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

int main() {
  char str1[MAXLEN * 2];
  char str2[MAXLEN];

  printf("Enter first string: ");
  fgets(str1, MAXLEN, stdin);
  uint32_t len1 = strlen(str1);
  str1[len1 - 1] = '\0';

  printf("Enter second string: ");
  fgets(str2, MAXLEN, stdin);
  uint32_t len2 = strlen(str2);
  str2[len2 - 1] = '\0';

  for (int i = 0; i < len1; i++) {
    str1[i + len1 - 1] = str1[i];
  }
  str1[(len1 - 1) * 2] = '\0';

  if (strstr(str1, str2)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}
