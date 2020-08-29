all: quiz

quiz.o: quiz.c handler.h
	gcc -c $<
handler.o: handler.c handler.h
	gcc -c $<
quiz: quiz.o handler.o
	gcc $^ -o $@
