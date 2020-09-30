#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
  stack * st = (stack * ) malloc(sizeof(stack));
  // initialize an empty stack
  create_stack(st);
  // check if empty
  print_if_empty(st);
  // push values
  push(st, 1);
  push(st, 13);
  push(st, 11);
  push(st, 13);
  push(st, 19);
  push(st, 19);
  push(st, 13);
  push(st, 91);
  puts("Some values were supposedly added, let's check ...");
  // check if still empty
  print_if_empty(st);
  // print it
  print_stack(st);
  // try to pop from end
  printf("\n%i was popped\n", pop(st));
  puts("\nStack now after popping out");
  print_stack(st);
  printf("\n%i was popped from left\n", popleft(st));
  puts("\nStack now after popping out from both sides:");
  print_stack(st);
  int * arr = (int * ) calloc(INIT_SIZE, sizeof(int));
  puts("\nNow Search for value 13");
  search(st, arr, 13);
  puts("Values exist at indices:");
  print_arr(arr);
  puts("\nNow Search for value 11");
  search(st, arr, 11);
  puts("Values exist at indices:");
  print_arr(arr);
  puts("\nNow Search for value 19");
  search(st, arr, 19);
  puts("Values exist at indices:");
  print_arr(arr);
  puts("\nNow let's free memory");
  clean(st);
}