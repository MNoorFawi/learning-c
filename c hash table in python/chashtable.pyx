cdef extern from "hash_table.h":
    ctypedef struct map:
        int key
        int value

    int hash_func(int key)
    int check_prime(int n)
    int get_prime(int n)
    map *dictionary_init()
    void insert(map *dictionary, int key, int value)
    void remove_element(map *dictionary, int key)
    void print_hashtable(map *dictionary)
    void size_of_hashtable()
    int get_size(map* dictionary)
    int search(map* dictionary, int key)

cdef class CDict:
    cdef map *m

    def __init__(self):
        self.m = dictionary_init()

    #@property
    #def key(self):
    #   return self.m.key

    #@property
    #def value(self):
    #    return self.m.value

    def insert_key(self, key, value):
        insert(self.m, key, value)

    def remove_key(self, key):
        remove_element(self.m, key)

    def display(self):
        return print_hashtable(self.m)

    def size(self):
        return get_size(self.m)

    def search(self, key):
        v = search(self.m, key)
        if v == -1:
            return "Key doesn't exist"
        return v


