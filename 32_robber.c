#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAXCHARS 100

int main() {
  char wanted[MAXCHARS];
  char line[MAXCHARS];
  uint32_t n;

  fgets(wanted, MAXCHARS, stdin);
  wanted[strcspn(wanted, "\n")] = '\0';

  scanf("%d\n", &n);

  for (int i = 0; i < n; i++) {
    fgets(line, MAXCHARS, stdin);
    line[strcspn(line, "\n")] = '\0';

    uint32_t count = 0;
    for (int j = 0; line[j] != '\0'; j++) {
      if (strchr(wanted, line[j])) {
        count++;
      }
    }

    printf("%d\n", count);
  }

  return 0;
}
