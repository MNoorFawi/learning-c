#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#define ARRLEN 1000001

// global struct to pass them as arguments to thread functions
typedef struct {
  int len, val, * number_array, middle;
}
arguments;

void linear_search(int * array, int len, int val) {
  puts("\n##### SEARCHING LINEARLY #####\n");
  clock_t t;
  t = clock();
  int i;
  for (i = 0; i < len; ++i) {
    if (array[i] == val)
      printf("\tValue %d is found at index %d\n", val, i);
  }
  t = clock() - t;
  double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds
  printf("\n\tLinear Search took %f seconds to execute \n", time_taken);
}

// error function to handle errors
void error(char * msg) {
  printf("%s: %s\n", msg, strerror(errno));
  exit(1);
}

// the left thread to search from left side 
// only accepts void* arguments and returns void* 
void * left(void * param) {
  arguments * args = (arguments * ) param; // converting void* param to struct pointer
  long i;
  for (i = args -> middle; i >= 0; --i) { // go back until end of array
    if (args -> number_array[i] == args -> val)
      break;
  }
  printf("\n\t(left) Value %d is found at index %ld\n", args -> val, i); // %ld to printf long
  return (void * ) i; // convert long to void*
}

void * right(void * param) {
  // we are not converting param to struct pointer as we can easily pass the pointer directly
  //arguments * args = (arguments * ) param;
  argument * args = param;
  int i; // i is long to be able to cast it from void* back and forth
  for (i = args -> middle; i < args -> len; ++i) {
    if (args -> number_array[i] == args -> val)
      break;
  }
  if (i >= args -> len) // if it goes outside the loop, it will never be bigger than len
    i = -1;
  printf("\n\t(right) Value %d is found at index %d\n", args -> val, i);
  // this would give a warning but ok, will not give if i was long
  return (void * ) i;
}

int main(int argc, char * argv[]) {

  char args;
  int number, capacity = ARRLEN, iter = 0;
  int * number_array = (int * ) malloc(capacity * sizeof(int));
  int middle;

  if (argc != 2) {
    printf("Error: You need only 1 arguemnt which is array file ...\n");
    return 1;
  }

  // read file into the array
  FILE * input = fopen(argv[1], "r");
  while (fscanf(input, "%d", & number) == 1) {

    if (iter >= capacity) {
      capacity = iter + 1; // new capacity to reallocate to dynamically expand array
      number_array = (int * ) realloc(number_array, sizeof(int) * capacity);
    }
    number_array[iter] = number;
    iter++;
  }
  fclose(input);
  middle = iter / 2;

  puts("\n*****ARRAY IS OF 1000001 SHUFFLED UNIQUE NUMBERS FROM 1 TO 1000000 BUT ONLY 741699 IS DUPLICATED*****\n");

  // assign the values into the struct to be passed to thread functions
  arguments * arg = (arguments * ) malloc(sizeof(arguments)); // initiate struct pointer
  arg -> len = iter; // iter has the length of the file
  arg -> middle = middle;
  // memory copy to assign arrays
  //memcpy(arg -> number_array, number_array, sizeof(arg -> number_array));
  arg -> number_array = number_array

  printf("Enter a Value to Search: ");
  while (scanf("%d", & arg -> val) == 1) { // assign the input to the val inside the struct

    // do linear search
    linear_search(number_array, iter, arg -> val);

    puts("\n##### SEARCHING THREADLY #####");
    clock_t t = clock();

    // threads
    pthread_t tleft;
    pthread_t tright;

    // create threads
    if (pthread_create( & tleft, NULL, left, (void * ) arg) == -1) // passing arg pointer as void*
      error("Can't create thread left\n");
    if (pthread_create( & tright, NULL, right, arg) == -1) // we are passing a pointer directly
      error("Can't create thread right\n");

    // join results
    void * result;
    if (pthread_join(tleft, & result) == -1)
      error("Can't join thread left\n");
    printf("\n\t*** Thread left returned %ld ***\n", (long) result); // printing void* as long
    if (pthread_join(tright, & result) == -1)
      error("Can't join thread right\n");
    printf("\t*** Thread right returned %d ***\n", (int) result); // here as int and would give a warning
    // can also be converted using * (int *) result

    // calculate thread search time
    t = clock() - t;
    double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds
    printf("\n\tThread Search took %f seconds to execute \n", time_taken);

    printf("\n\nEnter a Value to Search: ");

  }

  return 0;
}
