#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "handler.h"

/* fscanf read from input files while scanf read from stdin
 * fgets requires buffer size (safe) while fscanf doesn't
 * fgets reads to a newline while fscanf reads up to whitespace*/

int main() {
    catch_signal(SIGINT, terminate); // to handle signals

    FILE * in , * out; 
    in = fopen("websites.txt", "r");
    out = fopen("urls.txt", "w");
    char web[STRLEN], command[STRLEN], url[STRLEN];

    pid_t pid = getpid(); // to get process id

    // dup2 changes location in the descriptors table
    // fileno(file) gets you number of file in descriptors table
    dup2(fileno(in), 0); // point the pipe to the in file instead of stdin
    dup2(fileno(out), 1); // redirect stdout to out file

    // piping two processes happens that way
    int pipefd[2]; // initialize the two sides
    // pipe in and out ends
    if (pipe(pipefd) == -1) {
        puts("\n\tUnable to create pipe\n");
        exit(1);
    }

    while (scanf("%255s", & web) == 1) { // use scanf because now stdin is 'in' file

        if (web[0] == '^') { // ^C Terminate
            sprintf(command, "\nkill -INT %d", pid); // to kill a running process from another process in terminal
            // just to output it
            puts(command);
            //system(command);
            kill(pid, SIGINT); // process kills itself

        } else {
            // INTER PROCESSES COMMUNICATIONS
            // write message from write end to read end
            write(pipefd[1], open_url(web), STRLEN);
            // read message from read end and process
            read(pipefd[0], url, STRLEN);
            // sprintf(url, open_url(web)); // write and read can be done easily with this command
            find_url(url); // printing will be to 'out' file now as it is stdout
        }
    }
    // we should never get here
    puts("\n\tAll websites have been opened\n\tChao!\n");
    return 0;
}

/* another way of piping than the one tried here
// read end
dup2(pipefd[0], 0);
close(pipefd[1]); // close write end
 // input code
// opens write end and close read end
dup2(pipefd[1], 1);
close(pipefd[0]);
 // output code
 */
