builddll:
	gcc -fPIC -c stack.c -o stack.o
	gcc -shared stack.o -o ./lib/libstack.dll.a
buildexe:
	gcc -c prog.c
	gcc prog.o -L./lib -lstack -o prog