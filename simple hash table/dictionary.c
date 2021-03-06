#include <stdio.h>
#include <stdlib.h>

typedef struct map
{
    int key;
    int value;
} map;

map *dictionary;
int capacity = 10;
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

void dictionary_init(){
    capacity = get_prime(capacity);
    dictionary = (map*)malloc(capacity*sizeof(map));
    int i;
    for(i = 0; i < capacity; i++){
        dictionary[i].key = 0;
        dictionary[i].value = 0;
    }
}

void insert(int key, int value){
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

void remove_element(int key){
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

void print_hashtable(){
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

int main(){
    int choice, key, value;
    int c = 0;
    dictionary_init();

    do{
    printf("\n1.Insert item in dictionary"
           "\n2.Remove item from dictionary"
           "\n3.Check the length of the dictionary"
           "\n4.Print the dictionary"
           "\n5.Get value from Key"
           "\n\n Please enter your choice: ");

    scanf("%i", &choice);
    switch(choice){
    case 1:
      printf("Enter key: ");
      scanf("%i", &key);
      printf("Enter value: ");
      scanf("%i", &value);
      insert(key, value);
      break;

    case 2:
      printf("Enter the key to delete: ");
      scanf("%i", &key);
      remove_element(key);
      break;

    case 3:
      size_of_hashtable();
      break;

    case 4:
      print_hashtable();
      break;

    case 5:
      printf("Enter the key to search: ");
      scanf("%i", &key);
      int hash = hash_func(key);
      if(dictionary[hash].key != 0 && dictionary[hash].value != 0){
        printf("Value at key (%i) is (%i)\n", key, dictionary[hash].value);
      } else{
      printf("\n\tKey doesn't exist\n");
      }
      break;

    default:
      printf("Invalid Input\n");
    }

    // to return interactively to the beginning of while
    printf("\nDo you want to continue (press 1 for yes): ");
    scanf("%d", &c);

    } while(c == 1);
}
