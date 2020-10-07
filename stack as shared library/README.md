# Creating a LIFO & FIFO Stack data structure in C that Accepts all multiple types

To check that the makefile is made perfectly with proper separator:
```bash
$cat -e -t -v  Makefile
```
Commands lines should start with **^I**.

In **Cygwin** before running program we should run this command first to include shared library which is lib folder:
```bash
$PATH="$PATH:./lib"
```

In **linux**:
```bash
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./lib
```

Let's run the program:

```bash
$make builddll

gcc -fPIC -c stack.c -o stack.o
gcc -shared stack.o -o ./lib/libstack.so

$make buildexe

gcc -c prog.c
gcc prog.o -L./lib -lstack -o prog

$./prog

NOTE: When creating the stack input should be
 0 for INT type stack, 1 for FLOAT and 2 for STRING

 ########### STRING STACK ###########

        Stack is empty

Some values were supposedly added, let's check ...

        Stack is not empty now

HI, HOLA, how are you, previet, merhaba, HOLA, Konnichiwa, Ciao,

Ciao was popped

Stack now after popping out
HI, HOLA, how are you, previet, merhaba, HOLA, Konnichiwa,

HI was popped from left

Stack now after popping out from both sides:
HOLA, how are you, previet, merhaba, HOLA, Konnichiwa,

Now Search for value merhaba
Values exist at indices:
3

Now Search for value HOLA
Values exist at indices:
0 4

Now let's free memory


 ########### FLOAT STACK ###########

        Stack is empty

Some values were supposedly added, let's check ...

        Stack is not empty now

1.30 3.10 1.10 1.30 1.90 1.90 1.30 9.10

9.10 was popped

Stack now after popping out
1.30 3.10 1.10 1.30 1.90 1.90 1.30

1.30 was popped from left

Stack now after popping out from both sides:
3.10 1.10 1.30 1.90 1.90 1.30

Now Search for value 1.3
Values exist at indices:
2 5

Now Search for value 1.1
Values exist at indices:
1

Now Search for value 1.9
Values exist at indices:
3 4

Now let's free memory


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
$
```

