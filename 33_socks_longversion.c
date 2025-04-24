#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10
#define MAXLEN 100

typedef struct {
  int size;
  char color[30];
  int count;
} Sock;

int main() {
  int n;
  scanf("%d\n", &n);

  Sock socks[MAXN];
  int sockCount = 0;

  for (int i = 0; i < n; i++) {
    char input[MAXLEN];
    fgets(input, MAXLEN, stdin);
    input[strcspn(input, "\n")] = '\0';

    char *type = strtok(input, " ");
    char *sizeStr = strtok(NULL, " ");
    char *color = strtok(NULL, " ");

    if (strcmp(type, "sock") != 0)
      continue;

    int size = atoi(sizeStr);

    int found = 0;
    for (int j = 0; j < sockCount; j++) {
      if (socks[j].size == size && strcmp(socks[j].color, color) == 0) {
        socks[j].count++;
        found = 1;
        break;
      }
    }

    if (!found) {
      socks[sockCount].size = size;
      strcpy(socks[sockCount].color, color);
      socks[sockCount].count = 1;
      sockCount++;
    }
  }

  int lost = 0;
  for (int i = 0; i < sockCount; i++) {
    if (socks[i].count % 2 == 1)
      lost++;
  }

  printf("%d\n", lost);
  for (int i = 0; i < sockCount; i++) {
    if (socks[i].count % 2 == 1) {
      printf("%d %s\n", socks[i].size, socks[i].color);
    }
  }

  return 0;
}
