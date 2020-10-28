```bash 
gcc -E dyn_func.c

...
...

void search_int(stack * st, int * arr, void * value) {
  int i, iter = 0;
  int value = * (int * ) val;

  for (i = st -> lindx; i <= st -> indx; ++i) {
    if (st -> val._int[i] == value) {
      arr[iter] = i - st -> lindx;
      iter++;
    }
  }
}
# 4 "dyn_func.c" 2

...
...

void search_float(stack * st, int * arr, void * value) {
  int i, iter = 0;
  float value = * (float * ) val;

  for (i = st -> lindx; i <= st -> indx; ++i) {
    if (st -> val._float[i] == value) {
      arr[iter] = i - st -> lindx;
      iter++;
    }
  }
}
# 10 "dyn_func.c" 2

...
...

void search_str(stack * st, int * arr, void * value) {
  int i, iter = 0;
  char* value = * (char* * ) val;

  for (i = st -> lindx; i <= st -> indx; ++i) {
    if (st -> val._str[i] == value) {
      arr[iter] = i - st -> lindx;
      iter++;
    }
  }
}
# 16 "dyn_func.c" 2
```
Also a macro can be defined at the command line while compiling as follows:
###### But first, the definition in the .c file should be removed/commented in order not to override the command line definition
```bash
$ gcc -E dyn_func.c -DTYPE=char* -DTYPE2=str

...
...

void search_str(stack * st, int * arr, void * value) {
  int i, iter = 0;
  char* value = * (char* * ) val;

  for (i = st -> lindx; i <= st -> indx; ++i) {
    if (st -> val._str[i] == value) {
      arr[iter] = i - st -> lindx;
      iter++;
    }
  }
}
```
