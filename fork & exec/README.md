# Running system calls or script using C

First, because I am on Windows machine, we need to install **Cygwin** to have the **fork()** function.

After downloading Cygwin, run this command in the terminal.
```bash
setup-x86_64.exe -q -P wget -P gcc-g++ -P make -P diffutils -P libmpfr-devel -P libgmp-devel -P libmpc-devel
```
We will use the [dvd_recommender.py](https://github.com/MNoorFawi/recommendation-engine-with-neo4j/blob/master/dvd_recommender.py) python script. The script is a recommender script built upon **neo4j** database and takes an argument, user, and prints recommendation.

Because it is built on Neo4j, we should start Neo4j first before running the program using this command:
```bash
neo4j console
```
All the repo to build the database and the model can be found [here](https://github.com/MNoorFawi/recommendation-engine-with-neo4j).

Now compile the script
```bash
gcc dvd_c_rec.c -o dvd_c
```

Now let's try it:
```bash
dvd_c.exe users.txt

User array is:

13, 11, 19, 91,

{'13': ['Goodfellas Salute',
        'Whisperer Giant',
        'Streetcar Intentions',
        'Fellowship Autumn',
        'Mob Duffel']}
{'11': ['Sweethearts Suspects',
        'Jason Trap',
        'Tights Dawn',
        'Island Exorcist',
        'Lust Lock']}
{'19': ['Fatal Haunted',
        'Sleepless Monsoon',
        'Dream Pickup',
        'Wonderland Christmas',
        'Closer Bang']}
{'91': ['Forrester Comancheros',
        'Greatest North',
        'Anaconda Confessions',
        'Bear Graceland',
        'Hanover Galaxy']}
```

or in linux or cygwin:
```bash
./dvd_c users.txt
```