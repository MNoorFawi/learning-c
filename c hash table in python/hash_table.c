#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

int capacity = 100;
int size = 0;

int hash_func(int key){
    return key % capacity;
}

int check_prime(int n){
    int i;
    if(n == 1 || n == 0){
        return 0;
    }
    for(i = 2; i < n / 2; i++){
        if(n % i == 0){
        return 0;
        }
    }
    return 1;
}

int get_prime(int n){
    if(n % 2 == 0){
        n++;
    }
    while(!check_prime(n)){
        n += 2;
    }
    return n;
}

map *dictionary_init(){
    capacity = get_prime(capacity);
    map *dictionary = (map*)malloc(capacity*sizeof(map));
    int i;
    for(i = 0; i < capacity; i++){
        dictionary[i].key = 0;
        dictionary[i].value = 0;
    }
    return dictionary;
}

void insert(map *dictionary, int key, int value){
    int hash = hash_func(key);
    if(dictionary[hash].value == 0){
        dictionary[hash].key = key;
        dictionary[hash].value = value;
        size++;
    }
    else if(dictionary[hash].key == key){
        dictionary[hash].value = value;
    }
    else{
        printf("\n\tCollision occured\n");
    }
}

void remove_element(map *dictionary, int key){
    int hash = hash_func(key);
    if(dictionary[hash].value == 0){
        printf("\n\tThis key does not exist\n");
    }
    else{
        dictionary[hash].key = 0;
        dictionary[hash].value = 0;
        size--;
    }
}

void print_hashtable(map *dictionary){
    int i;
    printf("\n{\n");
    for(i = 0; i < capacity; i++){
        if(dictionary[i].value != 0 && dictionary[i].key != 0){
            printf("\t%i: %i\n", dictionary[i].key, dictionary[i].value);
        }
    }
    printf("}\n");
}

void size_of_hashtable(){
    printf("\nNumber of key-value pairs in the dictionary is: %i\n", size);
}

int get_size(map* dictionary){
    return size;
}

int search(map* dictionary, int key){
    int hash = hash_func(key);
    if(dictionary[hash].key != 0 && dictionary[hash].value != 0){
        return dictionary[hash].value;
    }else{
        return -1;
    }
}
