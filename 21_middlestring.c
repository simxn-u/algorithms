#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1024

int main() {
  char input[MAXLEN];
  fgets(input, MAXLEN, stdin);
  input[strcspn(input, "\n")] = '\0';

  printf("You entered: %s\n", input);

  int count = 1;
  for (int i = 0; input[i]; i++) {
    if (input[i] == ' ')
      count++;
  }

  char **words = malloc(count * sizeof(char *));
  int pos = 0;

  for (int i = 0; i < count; i++) {
    words[i] = malloc(MAXLEN * sizeof(char));
    int k = 0;
    while (input[pos] != ' ' && input[pos] != '\0') {
      words[i][k++] = input[pos++];
    }
    words[i][k] = '\0';
    pos++;
  }

  if ((count - 1) % 2 == 0) {
    printf("%s\n", words[(count - 1) / 2]);
  } else {
    printf("%s%s\n", words[count / 2 - 1], words[count / 2]);
  }

  for (int i = 0; i < count; i++) {
    free(words[i]);
  }
  free(words);

  return 0;
}
