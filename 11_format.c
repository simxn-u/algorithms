#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 256

int main() {
  char input[MAXLEN], format[MAXLEN], output[MAXLEN];
  printf("Enter the input: ");
  scanf("%s", input);
  getchar();

  printf("Enter the format: ");
  fgets(format, MAXLEN, stdin);
  format[strlen(format) - 1] = '\0';

  int j = 0;
  for (int i = 0; i < strlen(format); i++) {
    if (isalpha(format[i])) {
      if (isupper(format[i])) {
        output[i] = toupper(input[j]);
      } else {
        output[i] = tolower(input[j]);
      }
      j++;
    } else {
      output[i] = format[i];
    }
  }
  output[strlen(format)] = '\0';

  printf("%s\n", output);
}
