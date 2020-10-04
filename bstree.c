#include <stdio.h>
#include <stdlib.h>

struct tnode {
  int data;
  struct tnode * lchild, * rchild;
};

typedef struct tnode tn;

tn * insert(tn * p, int val) {
  tn * temp1, * temp2;

  if (p == NULL) {
    p = (tn * ) malloc(sizeof(tn)); // insert new node as root
    if (p == NULL) {
      puts("\tCannot Allocate");
      exit(0);
    }
    p -> data = val;
    p -> lchild = p -> rchild = NULL;
  } else {
    temp1 = p;
    /*traverse the tree to get a pointer to that node whose child
    will be the newly created node*/
    while (temp1 != NULL) {
      temp2 = temp1;
      if (temp1 -> data > val)
        temp1 = temp1 -> lchild;
      else
        temp1 = temp1 -> rchild;
    }
    if (temp2 -> data > val) {
      temp2 -> lchild = (tn * ) malloc(sizeof(tn));
      // inserts the newly created node as left child
      temp2 = temp2 -> lchild;
      if (temp2 == NULL) {
        puts("\tCannot Allocate");
        exit(0);
      }
      temp2 -> data = val;
      temp2 -> lchild = temp2 -> rchild = NULL;
    } else {
      temp2 -> rchild = (tn * ) malloc(sizeof(tn));
      temp2 = temp2 -> rchild;
      temp2 -> data = val;
      temp2 -> lchild = temp2 -> rchild = NULL;
    }
  }
  return p;
}

void inorder(tn * p) {
  tn * stack[100];
  int top = -1;
  if (p != NULL) {
    top++;
    stack[top] = p;
    p = p -> lchild;
    while (top >= 0) {
      while (p != NULL) {
        top++;
        stack[top] = p;
        p = p -> lchild;
      }

      p = stack[top];
      top--;
      printf("%d -> ", p -> data);
      p = p -> rchild;
      if (p != NULL) {
        top++;
        stack[top] = p;
        p = p -> lchild;
      }
    }
  }
}

int count(tn * p) {
  if (p == NULL)
    return 0;
  else {
    if (p -> lchild == NULL && p -> rchild == NULL)
      return 1;
    else
      return 1 + (count(p -> lchild) + count(p -> rchild));
  }
}

tn * search(tn * p, int key) {
  tn * temp;
  temp = p;
  while (temp != NULL) {
    if (temp -> data == key)
      return temp;
    else {
      if (temp -> data > key)
        temp = temp -> lchild;
      else
        temp = temp -> rchild;
    }
  }
  return NULL;
}

/*a function to get a pointer to the node whose data value is
given as well as the pointer to its root */
tn * getptr(tn * p, int key, tn ** y) {
  tn * temp;
  if (p == NULL)
    return NULL;
  temp = p;
  * y = NULL;
  while (temp != NULL) {
    if (temp -> data == key)
      return temp;
    else {
      * y = temp; // store this pointer as root
      if (temp -> data > key)
        temp = temp -> lchild;
      else
        temp = temp -> rchild;
    }
  }
  return NULL;
}

/* a function to delete the node whose data value is given */
tn * delete(tn * p, int val) {
  tn * x, * y, * temp;
  x = getptr(p, val, & y);
  if (x == NULL) {
    puts("\tThe node does not exist");
    return p;
  } else {
    // this code for deleting root node
    if (x == p) {
      temp = x -> rchild;
      y = x -> rchild;
      p = temp;
      while (temp -> rchild != NULL) {
        temp = temp -> rchild;
      }
      temp -> rchild = y;
      free(x);
      return p;
    }
    /* this code is for deleting node having both children */
    if (x -> lchild != NULL && x -> rchild != NULL) {
      if (y -> lchild == x) {
        temp = x -> lchild;
        y -> lchild = x -> lchild;
        while (temp -> rchild != NULL)
          temp = temp -> rchild;
        temp -> rchild = x -> rchild;
        x -> lchild = NULL;
        x -> rchild = NULL;
      } else {
        temp = x -> rchild;
        y -> rchild = x -> rchild;
        while (temp -> lchild != NULL)
          temp = temp -> lchild;
        temp -> lchild = x -> lchild;
        x -> lchild = NULL;
        x -> rchild = NULL;
      }
      free(x);
      return p;
    }
    /* this code is for deleting a node with one child */
    if (x -> lchild == NULL && x -> rchild != NULL) {
      if (y -> lchild == x)
        y -> lchild = x -> rchild;
      else
        y -> rchild = x -> rchild;
      x -> rchild = NULL;
      free(x);
      return p;
    }
    if (x -> lchild != NULL && x -> rchild == NULL) {
      if (y -> lchild == x)
        y -> lchild = x -> rchild;
      else
        y -> rchild = x -> lchild;
      x -> lchild = NULL;
      free(x);
      return p;
    }

    /* this code is for deleting a node with no child */
    if (x -> lchild == NULL && x -> rchild == NULL) {
      if (y -> lchild == x)
        y -> lchild = NULL;
      else
        y -> rchild = NULL;
      free(x);
      return p;
    }
  }
}

void main() {
  tn * root = NULL, * temp = NULL;
  int n, x;
  printf("Enter the number of nodes\n");
  scanf("%d", & n);
  while (n--> 0) {
    printf("Enter the data value\n");
    scanf("%d", & x);
    root = insert(root, x);
  }
  puts("The created tree is:");
  inorder(root);
  printf("\nThe number of nodes in tree are:%d\n", count(root));
  puts("Enter the value of the node to be searched for");
  scanf("%d", & n);
  temp = search(root, n);
  if (temp != NULL)
    puts("the data value is present in the tree");
  else
    puts("the data value is not present in the tree");
  puts("Enter the value of the node to be deleted");
  scanf("%d", & n);
  root = delete(root, n);
  puts("The tree after deletion is:\n");
  inorder(root);
}
