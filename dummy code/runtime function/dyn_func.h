#define INIT_SIZE 10000000

typedef enum {
  INT,
  FLOAT,
  STR
}
Type;

struct stck {
  Type type;
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

#define PASTE(x, y) x ## y

#define SEARCH_VAL(Type) PASTE(search_, Type)
#define VAL_TYPE(Type) PASTE(st -> val._, Type)

void SEARCH_VAL(TYPE2)(stack * st, int * arr, void * value) {
  int i, iter = 0;
  TYPE value = * (TYPE * ) val;

  for (i = st -> lindx; i <= st -> indx; ++i) {
    if (VAL_TYPE(TYPE2)[i] == value) {
      arr[iter] = i - st -> lindx;
      iter++;
    }
  }
}