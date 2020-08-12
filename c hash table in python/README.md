# Implementing a hash table written in C in Python through Cython

Compile the scripts
```bash
python setup.py build_ext --inplace
```

Now we have the python module, let's try it in python console:
```python
from c_hashtable import *
c_dict = CDict()

print(c_dict.size())
# 0

c_dict.insert_key(13, 11)

print(c_dict.size())
# 1

c_dict.display()

# {
#        13: 11
# }

c_dict.remove_key(11)

        This key does not exist

c_dict.remove_key(13)
c_dict.display()

{
}

c_dict.insert_key(19, 91)
c_dict.search(19)
# 91
```