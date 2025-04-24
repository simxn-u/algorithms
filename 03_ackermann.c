#include <stdio.h>

int32_t ackermann(int32_t m, int32_t n) {
  if (m == 0) {
    return n + 1;
  } else if (n == 0) {
    return ackermann(m - 1, 1);
  } else {
    return ackermann(m - 1, ackermann(m, n - 1));
  }
}

int main() {
  int32_t m, n;
  printf("Enter m: ");
  scanf("%d", &m);
  printf("Enter n: ");
  scanf("%d", &n);

  int32_t result;
  result = ackermann(m, n);
  printf("%d\n", result);
}
