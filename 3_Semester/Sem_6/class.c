#include <stdio.h>

int main()
{
    int a =123;
    int* p = &a;
    printf("%x\n", sizeof(p));
}