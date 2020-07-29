range_bs.o: range_bs.c sort.h
	gcc -c range_bs.c
sort.o: sort.h sort.c
	gcc -c sort.c
range_bs: range_bs.o sort.o
	gcc range_bs.o sort.o -o range_bs