# Random code to learn how to move inside the descriptors table, pipe processes, kill and handle signals

Compile:
```bash
$ make

gcc -c football_news.c
gcc -c handler.c
gcc football_news.o handler.o -o football_news
```
Websites file which will be the *stdin* inside the program
```text
marca
as
mundodeportivo
^C
```
**^C** to make the program kill itself.

Run:
```bash
./football_news
```
Result in browser:
![url_browser](./urls.jpg)

And **urls** file which was the *stdout* inside the program is now looking like this:
```text
url is:  www.marca.com
url is:  www.as.com
url is:  www.mundodeportivo.com

kill -INT 1472

	I received ^C I have to run away!
	Hasta la vista ....

```