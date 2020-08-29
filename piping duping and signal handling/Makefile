all: football_news

football_news.o: football_news.c handler.h
	gcc -c $<
handler.o: handler.c handler.h
	gcc -c $<
football_news: football_news.o handler.o
	gcc $^ -o football_news