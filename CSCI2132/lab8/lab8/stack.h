#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#include "bit.h"

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(Bit i);
Bit pop(void);
void stack_overflow(void);
void stack_underflow(void);

#endif
