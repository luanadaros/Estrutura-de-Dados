#include "stack.h"

struct stack {
    ForwardList * data;
};

Stack * stack_construct(){
    Stack * s = (Stack *)malloc(sizeof(Stack));
    s->data = forward_list_construct();
}

void stack_destroy(Stack *s){
    forward_list_destroy(s->data);
    free(s);
}

void stack_push_front(Stack *s, data_type data){
    
}

data_type stack_pop_front(Stack *);