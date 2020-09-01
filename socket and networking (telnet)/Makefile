all: internet_quiz

internet_quiz.o: internet_quiz.c helper.h
	gcc -c $<
helper.o: helper.c helper.h
	gcc -c $<
internet_quiz: internet_quiz.o helper.o
	gcc $^ -o $@
