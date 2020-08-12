typedef struct{
    int key;
    int value;
} map;

int hash_func(int key);
int check_prime(int n);
int get_prime(int n);
map *dictionary_init();
void insert(map *dictionary, int key, int value);
void remove_element(map *dictionary, int key);
void print_hashtable(map *dictionary);
void size_of_hashtable();
int get_size(map* dictionary);
int search(map* dictionary, int key);
