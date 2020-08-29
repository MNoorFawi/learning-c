# Practicing Signal Raising and Alarm Signals through a quiz game

Compile:
```bash
$ make

gcc -c quiz.c
gcc -c handler.c
gcc quiz.o handler.o -o quiz
```

Run:
1) Going through all questions successfully
```bash
$ ./quiz

Who's the Balon d'Or winner 2006?
Cannavaro

Who won 1954 world cup ?
Germany

What team won UCL the most?
Real Madrid

What team won 2008 Euro?
Spain

        Final Score: 4
```
2) Waiting for more than 10 seconds
```bash
$ ./quiz

Who's the Balon d'Or winner 2006?
Cannavaro

Who won 1954 world cup ?

        TIME'S UP!

        Final score: 1
```
3) Interrupting the program inputing ^C
```bash
$ ./quiz

Who's the Balon d'Or winner 2006?
Cannavaro

Who won 1954 world cup ?
Germany

What team won UCL the most?

        Final score: 2
```