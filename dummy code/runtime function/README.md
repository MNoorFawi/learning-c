```bash 
gcc -E dyn_func.c

...
...

void search_int(stack * st, int * arr, void * val) {
  int i, iter = 0;
  int value;

  if (st -> type == 2) {
    value = val;
    for (i = st -> lindx; i <= st -> indx; ++i) {
      if (strcmp(st -> val._int[i], value) == 0) {
        arr[iter] = i - st -> lindx;
        iter++;
      }
    }
  } else {
    value = * (int * ) val;
    for (i = st -> lindx; i <= st -> indx; ++i) {
      if (st -> val._int[i] == value) {
        arr[iter] = i - st -> lindx;
        iter++;
      }
    }
  }
}

...
...

void search_float(stack * st, int * arr, void * val) {
  int i, iter = 0;
  float value;

  if (st -> type == 2) {
    value = val;
    for (i = st -> lindx; i <= st -> indx; ++i) {
      if (strcmp(st -> val._float[i], value) == 0) {
        arr[iter] = i - st -> lindx;
        iter++;
      }
    }
  } else {
    value = * (float * ) val;
    for (i = st -> lindx; i <= st -> indx; ++i) {
      if (st -> val._float[i] == value) {
        arr[iter] = i - st -> lindx;
        iter++;
      }
    }
  }
}

...
...

void search_str(stack * st, int * arr, void * val) {
  int i, iter = 0;
  char* value;

  if (st -> type == 2) {
    value = val;
    for (i = st -> lindx; i <= st -> indx; ++i) {
      if (strcmp(st -> val._str[i], value) == 0) {
        arr[iter] = i - st -> lindx;
        iter++;
      }
    }
  } else {
    value = * (char* * ) val;
    for (i = st -> lindx; i <= st -> indx; ++i) {
      if (st -> val._str[i] == value) {
        arr[iter] = i - st -> lindx;
        iter++;
      }
    }
  }
}
```
Also a macro can be defined at the command line while compiling as follows:
###### But first, the definition in the .c file should be removed/commented in order not to override the command line definition
```bash
$ gcc -E dyn_func.c -DTYPE=char* -DTYPE2=str

...
...

void search_str(stack * st, int * arr, void * val) {
  int i, iter = 0;
  char* value;

  if (st -> type == 2) {
    value = val;
    for (i = st -> lindx; i <= st -> indx; ++i) {
      if (strcmp(st -> val._str[i], value) == 0) {
        arr[iter] = i - st -> lindx;
        iter++;
      }
    }
  } else {
    value = * (char* * ) val;
    for (i = st -> lindx; i <= st -> indx; ++i) {
      if (st -> val._str[i] == value) {
        arr[iter] = i - st -> lindx;
        iter++;
      }
    }
  }
}
```

### Running a toy example using dynamic macro definition at compile time to dynamically change functions behavior
```bash
gcc dyn_func_stack.c -DTYPE=int -DTYPE2=int -o prog
```

This might produce some warnings, just ignore them!

```bash
./prog

 ########### INTEGER STACK ###########

        Stack is empty

Some values were supposedly added, let's check ...

        Stack is not empty now

1 13 11 13 19 19 13 91

91 was popped

Stack now after popping out
1 13 11 13 19 19 13

1 was popped from left

Stack now after popping out from both sides:
13 11 13 19 19 13

Now Search for value 13
Values exist at indices:
0 2 5

Now Search for value 11
Values exist at indices:
1

Now Search for value 19
Values exist at indices:
3 4

Now let's free memory
```
**The search function which is dynamically behaves based on the defined macro seems to work fine**
