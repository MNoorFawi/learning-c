# Implementing range binary search in C

Run the make file to produce the program: (My machine is windows)
```bash
$ mingw32-make range_bs

gcc -c range_bs.c
gcc -c sort.c
gcc range_bs.o sort.o -o range_bs
$
```

Run the program:
```bash
$ range_bs.exe

Error: You need only 1 arguemnt which is array file ...
```
Run the program on an example file:
```bash
$ range_bs.exe example_array.txt

2 3 3 4 4 5 5 7 9 10
Enter a Value to Search: 4
4 is at index 3 till index 4
Enter a Value to Search: 5
5 is at index 5 till index 6
Enter a Value to Search: 7
7 is at index 7 till index 7
Enter a Value to Search: 9
9 is at index 8 till index 8
Enter a Value to Search: -4
-4 is at index -1 till index -1
Enter a Value to Search: 11
11 is at index -1 till index -1
Enter a Value to Search: ^D
$
```