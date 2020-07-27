binary_search.o: binary_search.c sort.h
	gcc -c binary_search.c
sort.o: sort.h sort.c
	gcc -c sort.c
binary_search: binary_search.o sort.o
	gcc binary_search.o sort.o -o binary_search