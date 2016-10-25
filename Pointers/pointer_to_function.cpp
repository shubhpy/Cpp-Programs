#include <stdio.h>
int print(int m)
{
    printf("%d ", m);
}

void my_int_func(int x)
{
    printf( "%d\n", x );
}

int main()
{
    void (*foo)(int);
    int (*ptrfun)(int);
    /* the ampersand is actually optional */
    foo = my_int_func;
    ptrfun = print;

    foo(12);
    ptrfun(20);

    return 0;
}
