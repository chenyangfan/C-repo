#include <stdio.h>

int main(void) {
  int  k, prev, value, temp;

  prev = 0;
  value = 1;

  printf("Enter a positive integer: ");
  scanf("%d", &k);

  if (k <= 0) {
    printf("The number entered is not positive.\n");
    return 1;
  }

  for (int i = 1; i < k; i++) {
    temp = value;
    value += prev;
    prev = temp;
  }

  printf("The result is %d.\n", value);

  return 0;
}
