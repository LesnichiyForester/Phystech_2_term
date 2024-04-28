#include <stdio.h>

int main()
{
    int a, b;
    int c;
    scanf("%i %i %i", &a, &b, &c);

    for (int i = a; i <= b; i++)
        if (i % c == 0)
            printf("%i ", i);
}
