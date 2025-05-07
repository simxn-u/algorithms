#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 10
#define TOKENMAXLEN 256

int main() {
  char input[MAXLEN];
  printf("Enter string to check: ");
  fgets(input, MAXLEN, stdin);
  uint32_t inputLen = strlen(input);
  input[inputLen - 1] = '\0';

  char token[TOKENMAXLEN];
  fgets(token, TOKENMAXLEN, stdin);
  uint32_t tokenLen = strlen(token);
  token[tokenLen - 1] = '\0';

  uint32_t count = 0;
  char *singleToken = strtok(token, " ");
  while (singleToken != NULL) {
    if (strstr(singleToken, input)) {
      count++;
    }
    singleToken = strtok(NULL, " ");
  }

  printf("%d\n", count);
}
