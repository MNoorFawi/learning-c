#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include "helper.h"

extern int listener_d;

char questions[][255] = {
  "Who's the 2006 Balon d'Or winner?",
  "Who won 1954 world cup?",
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

int main(int argc, char * argv[]) {
  signal(SIGINT, handle_shutdown); // handle interrupt signal
  listener_d = open_listener_socket(); // open socket
  bind_to_port(listener_d, 1311); // bind_to_port
  if (listen(listener_d, 10) == -1) // to trigger a function it is better to wrap it in false if and print error
    error("Can't listen");
  struct sockaddr_storage client_addr;
  unsigned int address_size = sizeof(client_addr);
  puts("Waiting for connection");
  
  while (1) {
    int connect_d = accept(listener_d, (struct sockaddr * ) & client_addr, & address_size);
	  
    if (connect_d == -1)
      error("Can't open secondary socket");
    
	if (!fork()) {
      close(listener_d);
      int i, score = 0;
      char answer[255], final[255], msg[255];
      
	  if (say(connect_d,
          "Football Quizzes World\r\nVersion 0.0.1\r\nVAMOS!!!!!!!!!\r\n") != -1) {
        
		for (i = 0; i < len; ++i) {
          sprintf(msg, "\n%s\r\n", questions[i]);
          say(connect_d, msg);
          //answer[0] = '\0'; // that way we can empty a string
          read_in(connect_d, answer, sizeof(answers[i]));

          if (strncasecmp(answers[i], answer, strlen(answers[i])))
            say(connect_d, "\nWrong!\r\n");
          
		  else {
			  say(connect_d, "\nGOLAZOOO!\r\n");
            score++;
          }
        }
        sprintf(final, "\n\tFinal Score: %i\r\n", score);
        say(connect_d, final);
      }
      close(connect_d);
      exit(0);
    }
    close(connect_d);
  }
  return 0;
}
