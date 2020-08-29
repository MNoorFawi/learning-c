#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "handler.h"

/* handling signals sent to the process even from within itself*/
int score = 0;

void end_game(int sig) { // handle interrupt signal
    printf("\n\tFinal score: %i\n", score);
    exit(0);
}

void times_up(int sig) { // handle alarm signal
    puts("\n\tTIME'S UP!");
    raise(SIGINT); // signal escalation from alarm to interrupt (within the process)
}
void error(char * msg) { // handle error messages
    printf("%s: %s\n", msg, strerror(errno));
    exit(1);
}