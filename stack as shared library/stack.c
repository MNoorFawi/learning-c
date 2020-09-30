#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void create_stack(stack * st) {
  st -> indx = -1;
  st -> size = 0;
  st -> lindx = 0;
  st -> val = (int * ) malloc(sizeof(int) * INIT_SIZE);
}

// check empty
int is_empty(stack * st) {
  if (st -> size == 0)
    return 1;
  else
    return 0;
}

// push/append
void push(stack * st, int new_val) {
  if (st -> size >= INIT_SIZE)
    st -> val = (int * ) realloc(st -> val, sizeof(int) * (st -> size + INIT_SIZE));
  st -> indx++;
  st -> val[st -> indx] = new_val;
  st -> size++;
}

// pop
int pop(stack * st) {
  if (is_empty(st)) {
    puts("\n\t STACK IS EMPTY\n");
    return -1;
  } else {
    int popped = st -> val[st -> indx];
    //printf("Value %i is popped from stack\n", st -> val[st -> indx]);
    st -> indx--;
    st -> size--;
    return popped;
  }
}

// pop left (FIFO)
int popleft(stack * st) {
  if (is_empty(st)) {
    puts("\n\t STACK IS EMPTY\n");
    return -1;
  } else {
    int popped = st -> val[st -> lindx];
    //printf("Value %i is popped from stack\n", st -> val[st -> indx]);
    st -> lindx++;
    st -> size--;
    return popped;
  }
}

// print stack
void print_stack(stack * st) {
  int i;
  for (i = st -> lindx; i <= st -> indx; i++) {
    printf("%i ", st -> val[i]);
  }
  printf("\n");
}

// length
int len(stack * st) {
  return st -> size;
}

void search(stack * st, int * arr, int value) {
  //static int arr[INIT_SIZE]; // to be able to return an array
  int i, iter = 0;

  for (i = st -> lindx; i <= st -> indx; ++i) {
    if (st -> val[i] == value) {
      arr[iter] = i - st -> lindx;
      iter++;
    }
  }
  //return arr;
}

// free memory
void clean(stack * st) {
  free(st -> val);
  free(st);
}

void print_if_empty(stack * st) {
  int empty = is_empty(st);
  if (empty)
    puts("\n\tStack is empty\n");
  else
    puts("\n\tStack is not empty now\n");
}

void print_arr(int * arr) {
  int i;
  for (i = 0; i < INIT_SIZE; ++i) {
    if (i > 0 && arr[i] == 0)
      break;
    printf("%i ", arr[i]);
    arr[i] = 0; // reset
  }
  puts("");
}