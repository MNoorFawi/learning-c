# Simple implementation of a hash table in C

Run the make file to produce the program: (My machine is windows)
```bash
$ mingw32-make c_dict

gcc -c dictionary.c
gcc dictionary.o -o c_dict
$
```

Run the program:
```bash
$ c_dict.exe

1.Insert item in dictionary
2.Remove item from dictionary
3.Check the length of the dictionary
4.Print the dictionary
5.Get value from Key

 Please enter your choice: 3

Number of key-value pairs in the dictionary is: 0

Do you want to continue (press 1 for yes): 1

1.Insert item in dictionary
2.Remove item from dictionary
3.Check the length of the dictionary
4.Print the dictionary
5.Get value from Key

 Please enter your choice: 1
Enter key: 11
Enter value: 13

Do you want to continue (press 1 for yes): 1

1.Insert item in dictionary
2.Remove item from dictionary
3.Check the length of the dictionary
4.Print the dictionary
5.Get value from Key

 Please enter your choice: 1
Enter key: 5
Enter value: 25

Do you want to continue (press 1 for yes): 1

1.Insert item in dictionary
2.Remove item from dictionary
3.Check the length of the dictionary
4.Print the dictionary
5.Get value from Key

 Please enter your choice: 4

{
        11: 13
        5: 25
}

Do you want to continue (press 1 for yes): 1

1.Insert item in dictionary
2.Remove item from dictionary
3.Check the length of the dictionary
4.Print the dictionary
5.Get value from Key

 Please enter your choice: 3

Number of key-value pairs in the dictionary is: 2

Do you want to continue (press 1 for yes): 1

1.Insert item in dictionary
2.Remove item from dictionary
3.Check the length of the dictionary
4.Print the dictionary
5.Get value from Key

 Please enter your choice: 5
Enter the key to search: 11
Value at key (11) is (13)

Do you want to continue (press 1 for yes): 1

1.Insert item in dictionary
2.Remove item from dictionary
3.Check the length of the dictionary
4.Print the dictionary
5.Get value from Key

 Please enter your choice: 5
Enter the key to search: 6

        Key doesn't exist

Do you want to continue (press 1 for yes): 1

1.Insert item in dictionary
2.Remove item from dictionary
3.Check the length of the dictionary
4.Print the dictionary
5.Get value from Key

 Please enter your choice: 2
Enter the key to delete: 11

Do you want to continue (press 1 for yes): 1

1.Insert item in dictionary
2.Remove item from dictionary
3.Check the length of the dictionary
4.Print the dictionary
5.Get value from Key

 Please enter your choice: 5
Enter the key to search: 11

        Key doesn't exist

Do you want to continue (press 1 for yes): 0
```

###### Most of the code was by the help of this article https://www.programiz.com/dsa/hash-table
