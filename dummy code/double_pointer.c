#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct dummy {
    int x;
};

void change_x(struct dummy** d)
{
    (*d)->x = 13;
}

int main()
{
    clock_t t;
    t = clock();

    struct dummy *a, *b, *c;
    a = (struct dummy*)malloc(sizeof(struct dummy));
	c = (struct dummy*)malloc(sizeof(struct dummy));
    a->x = 3;
    b = a;
	c->x = 7;

    puts("");
    printf("a->x is %i\n", a->x);
    printf("b->x is %i\n", b->x);
	printf("c->x is %i\n", c->x);

    puts("\nNow Changing x only in b to 4...");

    b->x = 4;
    printf("b->x is now %i\n", b->x);
    printf("a->x is now %i\n", a->x);
	printf("c->x is now %i\n", c->x);

    puts("\n\tdouble pointer to manipulate pointers inside functions ...");
    puts("\nChanging a->x inside a function to 13");
    change_x(&a);
    printf("b->x is now %i\n", b->x);
    printf("a->x is now %i\n", a->x);
	printf("c->x is now %i\n", c->x);
    printf("Address of a is %p while address of b is %p\n", &a, &b);
    printf("Address of x in a is %p and address of x in b is %p \nwhile address of x in c is %p\n", &a->x, &b->x, &c->x);
    puts("\n\tTwo different pointers with different addresses pointing to the same value (a & b) \nwhile c is having its own x value");

    puts("\nNow time ...");
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("\n\tdummy took %f minutes to execute \n", time_taken / 60);
    return 0;
}
