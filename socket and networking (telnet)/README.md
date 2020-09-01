# Practicing Socket and Networking in C implementing a Quiz Server

Most of the functions and the code were written thanks to the great [Head First C](https://www.oreilly.com/library/view/head-first-c/9781449335649/) book.

The server when started can be called from multiple clients at once.

Here we will use **telnet** to simply connect with the server and have the quiz.

Compile using the **Makefile**
```bash
$ make
gcc -c internet_quiz.c
gcc -c helper.c
gcc internet_quiz.o helper.o -o internet_quiz
```

Then we will run the server
```bash
$ ./internet_quiz
Waiting for connection
```

Now the server is waiting for connection

Let's connect to it from a different command line console (the port is 1311)
```bash
telnet 127.0.0.1 1311

Football Quizzes World
Version 0.0.1
VAMOS!!!!!!!!!

Who's the 2006 Balon d'Or winner?
Cannavaro

GOLAZOOO!

Who won 1954 world cup?
Brazil

Wrong!

What team won UCL the most?
real madrid

GOLAZOOO!

What team won 2008 Euro?
Spain

GOLAZOOO!

        Final Score: 3

```

We had the quiz successfully and we can have multiple players at once.

Let's now stop the server by simply interrupting it using ^C command
```bash
$ ./internet_quiz
Waiting for connection

        Hasta Luego Champ!

```

The message shows that signal handling is also working well.