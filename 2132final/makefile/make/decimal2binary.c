#include <stdio.h>

#include "bit.h"
#include "stack.h"

int main(void) {
  int decimal;
  Bit bit;

  printf("Enter a decimal integer: ");
  scanf("%d", &decimal);

  while (decimal > 0) {
    bit = decimal % 2;
    push(bit);
    decimal /= 2;
  }

  printf("This number can be expressed in binary as: ");

  while (!is_empty()) {
    printf("%d", pop());
  }

  printf("\n");

  return 0;
}
