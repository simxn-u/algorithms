#include <stdio.h>

void encrypt(char *input, char *output) {
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] >= 'a' && input[i] <= 'z') {
      output[i] = 'z' - (input[i] - 'a');
    } else if (input[i] >= 'A' && input[i] <= 'Z') {
      output[i] = 'Z' - (input[i] - 'A');
    } else {
      output[i] = input[i];
    }
  }
}

int main() {
  char input[100];
  char output[100];
  printf("Enter the string to decrypt: ");
  scanf("%s", input);
  encrypt(input, output);
  printf("Decrypted string: %s\n", output);
  return 0;
}
