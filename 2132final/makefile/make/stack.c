#include <stdio.h>
#include <stdlib.h>

#include "bit.h"
#include "stack.h"

#define STACK_SIZE 100

Bit contents[STACK_SIZE];
int top = 0;


void make_empty(void) {
  top = 0;
}

bool is_empty(void) {
  return top == 0;
}

bool is_full(void) {
  return top == STACK_SIZE;
}

void push(Bit i) {
  if (is_full())
    stack_overflow();
  else
    contents[top++] = i;
}

Bit pop(void) {
  if (is_empty())
    stack_underflow();
  else
    return contents[--top];
}

void stack_overflow(void) {
  printf("Error: stack overflow!\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Error: stack underflow!\n");
  exit(EXIT_FAILURE);
}
