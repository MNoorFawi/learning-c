#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sort.h"

int binary_search(int *array, size_t len, int val) {
    int i = 0;
	int j = len - 1;
    while(i <= j) {
        int k = i + ((j - i) / 2);
        if (array[k] == val)
            return k;
        else if (array[k] < val)
            i = k + 1;
        else
            j = k - 1;
    }
	// not found
    return -1;
}
 
int main(int argc, char *argv[]) {
	
	char args;
	FILE *input;
	int number, val;
	int iter = 0;
	//int b;
	int number_array[10];// = (int*)malloc(10 * sizeof *number_array);
	size_t len;
	
	while((args = getopt(argc, argv, "f:s")) != EOF){
		switch(args){
			case 'f':
				input = fopen(optarg, "r");
				while(fscanf(input, "%i", &number) == 1){
					//len = sizeof(number_array) / sizeof(number_array[0]);
					//printf("%i, %i, %i\n", number, iter, len);
					//if(iter >= len){
					//	b = iter + 1;
					//	number_array = (int*)realloc(number_array, sizeof(int)*iter+1);
					//}
					number_array[iter] = number;
					iter++;
				}
				fclose(input);
				len = sizeof(number_array) / sizeof(number_array[0]);
				break;
			case 's':
				sorted(number_array, len);
				break;
		}
	}
	argc -= optind;
	argv += optind;
	
	print_array(number_array, len);
	
	printf("Enter a Value to Search: ");
	while(scanf_s("%i", &val) == 1){
		printf("%i is at index %i\n", val, 
				binary_search(number_array, len, val));
		printf("Enter a Value to Search: ");
	}
	// free(number_array);
	return 0;
}

 