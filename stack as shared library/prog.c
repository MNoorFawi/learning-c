#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
  void * ptr;
  int i;
  float f;
  puts("\nNOTE: When creating the stack input should be\n 0 for INT type stack, 1 for FLOAT and 2 for STRING");
  stack * st = (stack * ) malloc(sizeof(stack));
  puts("\n ########### STRING STACK ###########");
  create_stack(st, 2);
  // check if empty
  print_if_empty(st);
  // push values
  push(st, "HI");
  push(st, "HOLA");
  push(st, "how are you");
  push(st, "previet");
  push(st, "merhaba");
  push(st, "HOLA");
  push(st, "Konnichiwa");
  push(st, "Ciao");
  puts("Some values were supposedly added, let's check ...");
  // check if still empty
  print_if_empty(st);
  // print it
  print_stack(st);
  // try to pop from end
  printf("\n%s was popped\n", pop(st, "2"));
  puts("\nStack now after popping out");
  print_stack(st);
  printf("\n%s was popped from left\n", popleft(st, "2"));
  puts("\nStack now after popping out from both sides:");
  print_stack(st);
  int * arr = (int * ) calloc(INIT_SIZE, sizeof(int));
  puts("\nNow Search for value merhaba");
  search(st, arr, "merhaba");
  puts("Values exist at indices:");
  print_arr(arr);
  puts("\nNow Search for value HOLA");
  search(st, arr, "HOLA"); // no need to cast a pointer to a pointer
  puts("Values exist at indices:");
  print_arr(arr);
  puts("\nNow let's free memory");
  clean(st);
  free(arr);
  puts("");
  st = (stack * ) malloc(sizeof(stack));
  puts("\n ########### FLOAT STACK ###########");
  create_stack(st, 1);
  // check if empty
  print_if_empty(st);
  // push values
  push(st, (float) 1.3);
  push(st, (float) 3.1);
  push(st, (float) 1.1);
  push(st, (float) 1.3);
  push(st, (float) 1.9);
  push(st, (float) 1.9);
  push(st, (float) 1.3);
  push(st, (float) 9.1);
  puts("Some values were supposedly added, let's check ...");
  // check if still empty
  print_if_empty(st);
  // print it
  print_stack(st);
  float input = 1.0;
  // try to pop from end
  printf("\n%.2f was popped\n", pop(st, input));
  puts("\nStack now after popping out");
  print_stack(st);
  printf("\n%.2f was popped from left\n", popleft(st, input));
  puts("\nStack now after popping out from both sides:");
  print_stack(st);
  arr = (int * ) calloc(INIT_SIZE, sizeof(int));
  f = 1.3;
  ptr = & f; // cast them to void* pointer
  puts("\nNow Search for value 1.3");
  search(st, arr, ptr);
  puts("Values exist at indices:");
  print_arr(arr);
  f = 1.1;
  ptr = & f;
  puts("\nNow Search for value 1.1");
  search(st, arr, ptr);
  puts("Values exist at indices:");
  print_arr(arr);
  f = 1.9;
  ptr = & f;
  puts("\nNow Search for value 1.9");
  search(st, arr, ptr);
  puts("Values exist at indices:");
  print_arr(arr);
  puts("\nNow let's free memory");
  clean(st);
  free(arr);
  puts("");
  st = (stack * ) malloc(sizeof(stack));
  puts("\n ########### INTEGER STACK ###########");
  create_stack(st, 0);
  // check if empty
  print_if_empty(st);
  int int_in = 1;
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
  printf("\n%i was popped\n", pop(st, int_in));
  puts("\nStack now after popping out");
  print_stack(st);
  printf("\n%i was popped from left\n", popleft(st, int_in));
  puts("\nStack now after popping out from both sides:");
  print_stack(st);
  arr = (int * ) calloc(INIT_SIZE, sizeof(int));
  puts("\nNow Search for value 13");
  i = 13;
  ptr = & i;
  search(st, arr, ptr);
  puts("Values exist at indices:");
  print_arr(arr);
  puts("\nNow Search for value 11");
  i = 11;
  ptr = & i;
  search(st, arr, ptr);
  puts("Values exist at indices:");
  print_arr(arr);
  puts("\nNow Search for value 19");
  i = 19;
  ptr = & i;
  search(st, arr, ptr);
  puts("Values exist at indices:");
  print_arr(arr);
  puts("\nNow let's free memory");
  clean(st);
  free(arr);
}