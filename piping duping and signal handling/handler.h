#define STRLEN 255
void terminate(int sig);
int catch_signal(int sig, void (*handler)(int));
char *open_url(char *webpage);
void find_url(char *string);