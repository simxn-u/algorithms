#include <stdint.h>
#include <stdio.h>

#define TICKETSIZE 6

int main() {
  uint32_t tickets;
  printf("Enter the number of tickets: ");
  scanf("%u", &tickets);

  for (int i = 1; i < tickets; i++) {
    char ticket[6];
    scanf("%s", ticket);

    int32_t sum = 0;
    for (int j = 0; j < TICKETSIZE / 2; j++) {
      sum += ticket[j] - ticket[TICKETSIZE - j - 1];
    }
    if (sum == 0) {
      printf("Lucky\n");
    } else {
      printf("Unlucky\n");
    }
  }
}
