#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void create_stack(stack *st){
    st->indx = -1;
    st->size = 0;
}

// check empty
int is_empty(stack *st){
    if(st->indx == -1)
        return 1;
    else
        return 0;
}

// push/append
void push(stack *st, int new_val){
    st->indx++;
    st->val[st->indx] = new_val;
    st->size++;
}

// pop
void pop(stack *st){
    if(is_empty(st)){
        puts("\n\t STACK IS EMPTY");
    }else{
        printf("Value %i is popped from stack\n", st->val[st->indx]);
        st->indx--;
        st->size--;
    }
}

// print stack
void print_stack(stack *st){
    int i;
    for(i = 0; i < st->size; i++){
        printf("%i ", st->val[i]);
    }
  printf("\n");
}