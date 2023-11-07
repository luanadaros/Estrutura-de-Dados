#ifndef STACK_H
#define STACK_Hq

#include "forward-list.h"

typedef struct stack Stack;

Stack * stack_construct();
void stack_destroy(Stack *);
void stack_push_front(Stack *, data_type);
data_type stack_pop_front(Stack *);

#endif