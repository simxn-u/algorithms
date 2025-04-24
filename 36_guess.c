#include <stdio.h>
#include <stdlib.h>

int main() {
  uint32_t number = random() % 100 + 1;
  printf("Guess a number between 1 and 100\n");
  uint32_t guess;
  do {
    scanf("%u", &guess);
    if (guess < number) {
      printf("Higher\n");
    } else if (guess > number) {
      printf("Lower\n");
    }
  } while (guess != number);
  printf("You guessed it!\n");
}
