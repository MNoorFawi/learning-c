void error(char * msg);
int open_listener_socket();
void bind_to_port(int socket, int port);
int say(int socket, char * s);
int read_in(int socket, char * buf, int len);
void handle_shutdown(int sig);