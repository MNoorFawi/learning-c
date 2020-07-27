# Implementing simple binary search in C

Run the make file to produce the program: (My machine is windows)
```bash
$ mingw32-make binary_search

gcc -c binary_search.c
gcc -c sort.c
gcc binary_search.o sort.o -o binary_search
$
```

Run the program on an example file:
```bash
$ binary_search.exe -f example_array.txt -s

-3 0 1 3 3 4 65 77 93 1902
Enter a Value to Search: 3
3 is at index 4
Enter a Value to Search: 77
77 is at index 7
Enter a Value to Search: -3
-3 is at index 0
Enter a Value to Search: 10
10 is at index -1
Enter a Value to Search: 25
25 is at index -1
Enter a Value to Search: ^D
$
```