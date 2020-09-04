# Using Threads to Search an array in both ways rather than linearly

Construct the array and the file using the R script
###### The file has a seed set to reproduce the same shuffled results
```bash
$ Rscript example_array.R
```
Compile the program:
```bash
$ gcc thread_search.c -o tsearch
```

Run the program on an example file:
```bash
$ ./tsearch example_array.txt

*****ARRAY IS OF 1000001 SHUFFLED UNIQUE NUMBERS FROM 1 TO 1000000 BUT ONLY 741699 IS DUPLICATED*****

Enter a Value to Search: 741699

##### SEARCHING LINEARLY #####

        Value 741699 is found at index 12
        Value 741699 is found at index 1000000

        Linear Search took 0.000000 seconds to execute

##### SEARCHING THREADLY #####

        (left) Value 741699 is found at index 12

        (right) Value 741699 is found at index 1000000

        *** Thread left returned 12 ***
        *** Thread right returned 1000000 ***

        Thread Search took 0.031000 seconds to execute


Enter a Value to Search: 0

##### SEARCHING LINEARLY #####


        Linear Search took 0.016000 seconds to execute

##### SEARCHING THREADLY #####

        (left) Value 0 is found at index -1

        (right) Value 0 is found at index -1

        *** Thread left returned -1 ***
        *** Thread right returned -1 ***

        Thread Search took 0.000000 seconds to execute


Enter a Value to Search: 2000000

##### SEARCHING LINEARLY #####


        Linear Search took 0.000000 seconds to execute

##### SEARCHING THREADLY #####

        (left) Value 2000000 is found at index -1

        (right) Value 2000000 is found at index -1

        *** Thread left returned -1 ***
        *** Thread right returned -1 ***

        Thread Search took 0.000000 seconds to execute


Enter a Value to Search: 71585

##### SEARCHING LINEARLY #####

        Value 71585 is found at index 64

        Linear Search took 0.000000 seconds to execute

##### SEARCHING THREADLY #####

        (left) Value 71585 is found at index 64

        (right) Value 71585 is found at index -1

        *** Thread left returned 64 ***
        *** Thread right returned -1 ***

        Thread Search took 0.000000 seconds to execute


Enter a Value to Search: 131191

##### SEARCHING LINEARLY #####

        Value 131191 is found at index 997887

        Linear Search took 0.016000 seconds to execute

##### SEARCHING THREADLY #####

        (left) Value 131191 is found at index -1

        (right) Value 131191 is found at index 997887

        *** Thread left returned -1 ***
        *** Thread right returned 997887 ***

        Thread Search took 0.000000 seconds to execute


Enter a Value to Search:

```