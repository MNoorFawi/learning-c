# Implementing Priority Queue with the aid of Linked List

Compile:
```bash
$ gcc priority_queue.c -o pq
```

Run:
```bash
$ ./pq

1.Insert tasks in the queue
2.Remove task from the queue
3.Display the queue

 Please enter your choice: 1

Enter task:
Sleep

Enter priority:
2

Do you want to continue (press 1 for yes or 0 to exit): 1
1.Insert tasks in the queue
2.Remove task from the queue
3.Display the queue

 Please enter your choice: 1

Enter task:
Share Memes

Enter priority:
3

Do you want to continue (press 1 for yes or 0 to exit): 1
1.Insert tasks in the queue
2.Remove task from the queue
3.Display the queue

 Please enter your choice: 3
{
        {'task': Share Memes, 'priority': 3.000000}
        {'task': Sleep, 'priority': 2.000000}
}

Do you want to continue (press 1 for yes or 0 to exit): 1
1.Insert tasks in the queue
2.Remove task from the queue
3.Display the queue

 Please enter your choice: 1

Enter task:
Eat

Enter priority:
1.5

Do you want to continue (press 1 for yes or 0 to exit): 1
1.Insert tasks in the queue
2.Remove task from the queue
3.Display the queue

 Please enter your choice: 1

Enter task:
Code

Enter priority:
5

Do you want to continue (press 1 for yes or 0 to exit): 1
1.Insert tasks in the queue
2.Remove task from the queue
3.Display the queue

 Please enter your choice: 3
{
        {'task': Code, 'priority': 5.000000}
        {'task': Share Memes, 'priority': 3.000000}
        {'task': Sleep, 'priority': 2.000000}
        {'task': Eat, 'priority': 1.500000}
}

Do you want to continue (press 1 for yes or 0 to exit): 1
1.Insert tasks in the queue
2.Remove task from the queue
3.Display the queue

 Please enter your choice: 1

Enter task:
Read

Enter priority:
4.25

Do you want to continue (press 1 for yes or 0 to exit): 1
1.Insert tasks in the queue
2.Remove task from the queue
3.Display the queue

 Please enter your choice: 3
{
        {'task': Code, 'priority': 5.000000}
        {'task': Read, 'priority': 4.250000}
        {'task': Share Memes, 'priority': 3.000000}
        {'task': Sleep, 'priority': 2.000000}
        {'task': Eat, 'priority': 1.500000}
}

Do you want to continue (press 1 for yes or 0 to exit): 1
1.Insert tasks in the queue
2.Remove task from the queue
3.Display the queue

 Please enter your choice: 2

Task (Code) with priority (5.000000) has been removed

Do you want to continue (press 1 for yes or 0 to exit): 1
1.Insert tasks in the queue
2.Remove task from the queue
3.Display the queue

 Please enter your choice: 2

Task (Read) with priority (4.250000) has been removed

Do you want to continue (press 1 for yes or 0 to exit): 1
1.Insert tasks in the queue
2.Remove task from the queue
3.Display the queue

 Please enter your choice: 2

Task (Share Memes) with priority (3.000000) has been removed

Do you want to continue (press 1 for yes or 0 to exit): 1
1.Insert tasks in the queue
2.Remove task from the queue
3.Display the queue

 Please enter your choice: 3
{
        {'task': Sleep, 'priority': 2.000000}
        {'task': Eat, 'priority': 1.500000}
}

Do you want to continue (press 1 for yes or 0 to exit): 1
1.Insert tasks in the queue
2.Remove task from the queue
3.Display the queue

 Please enter your choice: 2

Task (Sleep) with priority (2.000000) has been removed

Do you want to continue (press 1 for yes or 0 to exit): 1
1.Insert tasks in the queue
2.Remove task from the queue
3.Display the queue

 Please enter your choice: 2

Task (Eat) with priority (1.500000) has been removed

Do you want to continue (press 1 for yes or 0 to exit): 1
1.Insert tasks in the queue
2.Remove task from the queue
3.Display the queue

 Please enter your choice: 2

        The queue is empty

Do you want to continue (press 1 for yes or 0 to exit): 1
1.Insert tasks in the queue
2.Remove task from the queue
3.Display the queue

 Please enter your choice: 0
Invalid Input


Do you want to continue (press 1 for yes or 0 to exit): 0
``` 