#define INIT_SIZE 10000000

// enum to switch between types
typedef enum {
  INT,
  FLOAT,
  STR
}
Type;
// initialize a stack
struct stck {
  Type type;
  // union to have only one memory allocated for all
  union {
    int * _int;
    float * _float;
    char _str[INIT_SIZE][100];
  }
  val;
  int indx;
  int lindx;
  int size;
};

typedef struct stck stack;
void create_stack(stack * st, int input_type);
int is_empty(stack * st);

// pushing functions for each type argument
void push_int(stack * st, int new_val);
void push_float(stack * st, float new_val);
void push_str(stack * st, char * new_val);

// poping functions for each type argument
int pop_int(stack * st, int input);
int popleft_int(stack * st, int input);
float pop_float(stack * st, float input);
float popleft_float(stack * st, float input);
char * pop_str(stack * st, char * input);
char * popleft_str(stack * st, char * input);

void print_stack(stack * st);
int len(stack * st);
void search(stack * st, int * arr, void * value);
void clean(stack * st);
void print_if_empty(stack * st);
void print_arr(int * arr);

// combining pushing and poping functions into one macro that handles argument type
#define push(x, y)\
_Generic((y), \
  int: push_int, float: push_float, char *: push_str, \
  default: push_int)(x, y)

#define pop(x, y)\
_Generic((y), \
  int: pop_int, float: pop_float, char *: pop_str, \
  default: pop_int)(x, y)

#define popleft(x, y)\
_Generic((y), \
  int: popleft_int, float: popleft_float, char *: popleft_str, \
  default: popleft_int)(x, y)
  
#define PASTE(x, y) x ## y

// Macros to help dynamically define the function based on input macro definition at compile time for TYPE & TYPE2
#define SEARCH_VAL(Type) PASTE(search_, Type)
#define VAL_TYPE(Type) PASTE(st -> val._, Type)

/* search for values
input value is void pointer to accept any type 
and cast it inside the function properly */
void SEARCH_VAL(TYPE2)(stack * st, int * arr, void * val) {
  int i, iter = 0;
  TYPE value;

  if (st -> type == 2) {
    value = val;
    for (i = st -> lindx; i <= st -> indx; ++i) {
      if (strcmp(VAL_TYPE(TYPE2)[i], value) == 0) {
        arr[iter] = i - st -> lindx;
        iter++;
      }
    }
  } else {
    value = * (TYPE * ) val;
    for (i = st -> lindx; i <= st -> indx; ++i) {
      if (VAL_TYPE(TYPE2)[i] == value) {
        arr[iter] = i - st -> lindx;
        iter++;
      }
    }
  }
}
