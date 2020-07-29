#include <stdio.h>
#include "sort.h" 
  
void swap(int *x, int *y) 
{ 
    int tmp = *x; 
    *x = *y; 
    *y = tmp; 
} 
  
void sorted(int *array, size_t len) 
{ 
    int i, j, min_idx; 
  
    for (i = 0; i < len - 1; i++) {   
        min_idx = i; 
        for (j = i + 1; j < len; j++) 
            if (array[j] < array[min_idx]) 
                min_idx = j; 
  
        swap(&array[min_idx], &array[i]); 
    } 
} 

void print_array(int *array, size_t len) 
{ 
    int i; 
    for (i = 0; i < len; i++) 
        printf("%i ", array[i]); 
    printf("\n"); 
} 
  