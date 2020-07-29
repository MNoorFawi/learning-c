#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sort.h"

void range_binary_search(int *array, int len, int val, int *res) {
    int right = 0;
    int left = 0;
    int middle;

    // not found
    if(val < array[0] || val > array[len - 1]){
        right = 0;
        left = -1;
    }

    // found
    else{
        while(right < len){
            middle = (right + len) / 2;
            if(val < array[middle])
                len = middle;
            else
                right = middle + 1;
        }
        len = right - 1;
        while(left < len){
            middle = (left + len) / 2;
            if(val > array[middle])
                left = middle + 1;
            else
                len = middle;
        }
    }
    res[0] = left;
    res[1] = right - 1;
}

int main(int argc, char *argv[]) {

	char args;
	int number, val, len;
	int iter = 0;
	int res[2];

	if(argc != 2){
	    printf("Error: You need only 1 arguemnt which is array file ...\n");
	    return 1;
	}

	int number_array[10];

	FILE *input = fopen(argv[1], "r");
	while(fscanf(input, "%i", &number) == 1){
	    number_array[iter] = number;
	    iter++;
    }
    fclose(input);
	len = sizeof(number_array) / sizeof(number_array[0]);

	sorted(number_array, len);
	print_array(number_array, len);

	printf("Enter a Value to Search: ");
	while(scanf_s("%i", &val) == 1){
	    range_binary_search(number_array, len, val, res);
		printf("%i is at index %i till index %i\n", val,
				res[0], res[1]);
		printf("Enter a Value to Search: ");
	}
	return 0;
}
