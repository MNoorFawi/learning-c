#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

void print_array(char *array[], int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%s, ", array[i]);
    printf("\n");
}

int main(int argc, char *argv[]){
	char id[20], cid[20]; // string of length 20
	int iter = 0;
	//int *b = malloc(sizeof(int));
	int b = 2; // initial capacity
	int i;
	char **user_array = malloc(b * sizeof(*user_array));
	//char user_array[4][20];
    FILE *input = fopen(argv[1], "r");
	while(fscanf(input, "%s", id) == 1){
	    if(iter >= b){
	        b = iter + 1; // new capacity to reallocate
		    user_array = realloc(user_array, b * sizeof(*user_array));
		}
		user_array[iter] = malloc(20 * sizeof(char*));
		strcpy(user_array[iter], id);
		iter++;
	}
	fclose(input);
	puts("User array is:\n");
	print_array(user_array, iter);

	for(i = 0; i < iter; i++){
	    pid_t pid = fork();
	    //cid = user_array[i];
	    sprintf(cid, "%s", user_array[i]);
	    //printf("User %s\n", cid);
	    if(pid == -1){
	        printf("\n\t Can't fork process: %s\n", strerror(errno));
	        // _exit(EXIT_FAILURE);
	        return 1;
	    }
	    // pid == 0
	    else if(!pid){
	        if(execlp("python", "python", "./dvd_recommender.py", cid, (char*)NULL) == -1){
                printf("\n\tCan't run script: %s\n", strerror(errno));
                return 1;
	        }
	        exit(0);
	    }
	    //else { // if(pid > 0){
	    //    int status;
	    //    waitpid(pid, &status, 0);
	    //}
	}
	return 0;
}