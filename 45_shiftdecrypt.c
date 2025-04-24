#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

int main() {
  char str1[MAXLEN];
  char str2[MAXLEN];
  printf("Enter encrypted string: ");
  fgets(str1, MAXLEN, stdin);
  uint32_t len1 = strlen(str1);
  str1[len1 - 1] = '\0';

  printf("Enter decrypted string: ");
  fgets(str2, MAXLEN, stdin);
  uint32_t len2 = strlen(str2);
  str2[len2 - 1] = '\0';

  if (len1 != len2) {
    printf("false\n");
    return 0;
  }

  for (int i = 0; i < len1 - 1; i++) {
    str1[i] = 'A' + (str1[i] + 26 - 4 - 'A') % 26;
  }

  printf("%s\n", str1);
  printf("%s\n", str2);

  strcmp(str1, str2) ? printf("false\n") : printf("true\n");
}
