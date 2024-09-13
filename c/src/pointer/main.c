#include <stdlib.h>
#include <stdio.h>

#include "util.h"

int func1(int);
int func2(int, int);
int func2(int, int);

int main(int argc, char *argv[])
{
    PRINTLN("[pointer]");

    // local variable, stack
    int a1 = 1;
    int a2 = 2;
    int diff_addr_a2a1 = &a2 - &a1;

    PRINTLN("&a1 = %p", &a1);
    PRINTLN("&a2 = %p", &a2);
    PRINTLN("diff_addr_a2a1 = %i", diff_addr_a2a1);

    int *a3;
    int *a4;
    // malloc at heap
    a3 = (int *)malloc(sizeof(int));
    a4 = (int *)malloc(sizeof(int));
    *a3 = 1;
    *a4 = 2;
    int diff_ptr_a4a3 = a4 - a3;
    // local variable, stack
    int diff_addr_a4a3 = &a4 - &a3;

    PRINTLN("a3 = %p", a3);
    PRINTLN("a4 = %p", a4);
    PRINTLN("diff_ptr_a4a3 = %i", diff_ptr_a4a3);

    PRINTLN("&a3 = %p", &a3);
    PRINTLN("&a4 = %p", &a4);
    PRINTLN("diff_addr_a4a3 = %i", diff_addr_a4a3);

    int (*fptr1)(int) = &func1;
    int a5 = fptr1(a1);

    PRINTLN("&a1 = %p", &a1);
    PRINTLN("&a5 = %p", &a5);
    PRINTLN("a5 = %i", a5);

    void *fptr2 = &func2;
    int a6 = (*(int (*)(int, int))fptr2)(a1, a2);
    int a7 = (*(typeof(func2) *)fptr2)(a1, a2);
    PRINTLN("a6 = %i", a6);
    PRINTLN("a7 = %i", a7);

    int *a8[10] = {NULL};
    a8[5] = (int *)malloc(sizeof(int));
    *a8[5] = 11;
    PRINTLN("*a8[5] = %i", *a8[5]);
    if (a8[4] == NULL)
    {
        PRINTLN("*a8[4] = NULL");
    }

    for (int i = 0; i < 10; i++)
    {
        if (a8[i] != NULL)
        {
            free(a8[i]);
            a8[i] = NULL;
        }
    }

    int a9[4] = {1, 2, 3, 4};
    int(*a10)[4] = &a9;
    PRINTLN("*a10[3] = %i", (*a10)[3]);

    int (*a11[4])(int, int) = {NULL};
    a11[3] = &func2;
    PRINTLN("(*a11[3])(a1, a2) = %i", (*a11[3])(a1, a2));

    int a12[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int(*a13)[2];
    a13 = &a12[0];
    PRINTLN("(*a13)[1] = %i", (*a13)[1]);
    a13++;
    PRINTLN("(*a13)[1] = %i", (*a13)[1]);

    return 0;
}

int func1(int x)
{
    return x;
}

int func2(int x, int y)
{
    return x + y;
}
