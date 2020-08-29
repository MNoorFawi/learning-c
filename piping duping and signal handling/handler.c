#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "handler.h"

/* handling signals sent to the process even from within itself*/

void terminate(int sig) {
    // this message should be printed in out file when process gets killed
    puts("\n\tI received ^C I have to run away!\n\tHasta la vista ....\n");
    exit(1);
}

int catch_signal(int sig, void( * handler)(int)) {
    /* from Head First C book */
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset( & action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, & action, NULL);
}

// open a website in the browser from command line
char * open_url(char * webpage) {
    /* to be able to return a string from a function to be used elsewhere
     * it should be in the heap*/
    char * command = (char * ) malloc(sizeof(char) * STRLEN);
    sprintf(command, "cmd /c start www.%s.com", webpage);
    //printf("%s\n", command); // print to write side of pipe
    system(command);
    return command;
}

void find_url(char * string) {
    char * url = strrchr(string, ' '); // finds last occurence of a character
    printf("url is: %s\n", url);
}