#include <stdio.h>
#include <stdlib.h>

void printarr(int **a);
void printdetail(int **a);
void print_ptr(int **a);

int main(){
	int **a;
	int i, j;
	
	// create an array of 3 int**
	a = (int**)malloc(3 * sizeof(int*));
    for(i = 0; i < 3; i++)
    {
        // assign each pointer to an array of int* of length 2
        a[i] = (int*)malloc(2 * sizeof(int));
        for(j = 0; j < 2; j++)
        {
            // assign each integer to j
            a[i][j] = j;
        }
    }
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 2; j++){
			a[i][j] = i;
		}
	}
	//printarr(a);
	printdetail(a);
	puts("Now using pointer");
	print_ptr(a);
}

void printarr(int **a){
	int i, j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 2; j++){
			printf("Value in array %i\n", a[i][j]);
		}
	}
}

void printdetail(int **a){
	int i, j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 2; j++){
			printf("Value in array in row %i is %i and address is %p\n", 
				   i, a[i][j], &a[i][j]);
		}
	}
}

void print_ptr(int **a){
	int i;
	int *b;
	for(i = 0; i < 3; i++){
		b = a[i];
		printf("value of pointer %i is %i and address is %8u\n", i, *b, b);
		b++;
	}
}