#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "handler.h"

extern int score;

char questions[][255] = {
        "Who's the Balon d'Or winner 2006?",
        "Who won 1954 world cup ?",
        "What team won UCL the most?",
        "What team won 2008 Euro?"
};
char answers[][255] = {
        "Cannavaro",
        "Germany",
        "Real Madrid",
        "Spain"
};
int len = sizeof(questions) / sizeof(questions[0]); // get length of an array

int main() {
    signal(SIGALRM, times_up);
    signal(SIGINT, end_game);
    int i;
    for (i = 0; i < len; ++i) {
        char answer[255];
        alarm(10); // alarm for 10 seconds
        printf("\n%s\n", questions[i]);
        //fgets(answer, 255, stdin);
        scanf(" %[^\t\n]255s", answer);
        if (strcmp(answer, answers[i]) == 0) // compare two strings (0 means identical)
            score++;
        else
            printf("\nWrong! Score: %i\n", score);
    }
    printf("\n\tFinal Score: %i\n", score);
    return 0;
}