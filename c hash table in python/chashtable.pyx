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

#ctypedef fused int_str:
#    int
#    str

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

    cpdef void insert_key(self, int key, int value):
        insert(self.m, key, value)

    cpdef void remove_key(self, int key):
        remove_element(self.m, key)

    cpdef display(self):
        print_hashtable(self.m)

    cpdef int size(self):
        return get_size(self.m)

    cpdef int search(self, int key):
        cdef int v = search(self.m, key)
        #cdef str x
        #if v == -1:
        #    x = "Key doesn't exist"
        #    return x
        return v


