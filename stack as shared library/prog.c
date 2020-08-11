#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void print_if_empty(stack *st){
    int empty = is_empty(st);
    if(empty)
        puts("\n\tStack is empty\n");
    else
        puts("\n\tStack is not empty now\n");
}

int main(){
    stack *st = (stack*)malloc(sizeof(stack));
    // initialize an empty stack
    create_stack(st);
    // check if empty
    print_if_empty(st);
    // push values
    push(st, 13);
    push(st, 11);
    push(st, 19);
    push(st, 91);
    puts("Some values were supposedly added, let's check ...");
    // check if still empty
    print_if_empty(st);
    // print it
    print_stack(st);
    // try to pop
    pop(st);
    puts("\nStack now after popping out");
    print_stack(st);
}