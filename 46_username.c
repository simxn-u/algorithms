#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100
#define LOWERLEN 3
#define UPPERLEN 20

int main() {
  char user[MAXLEN];
  printf("Enter username: ");
  fgets(user, MAXLEN, stdin);
  uint32_t len = strlen(user) - 1;
  user[len] = '\0';

  if (len > UPPERLEN) {
    printf("Username too long!\n");
    return -1;
  }
  if (len < LOWERLEN) {
    printf("Username too short!\n");
    return -1;
  }

  for (int i = 0; i < len; i++) {
    if (!isalnum(user[i])) {
      printf("Username contains invalid characters!\n");
      return -1;
    }
  }
  printf("Username '%s' is valid!\n", user);
}
