#include <stdio.h>

int main()
{
    int n; // up to 99 for lined-up answer
    scanf("%i", &n);
    for (int i = 1; i <= n; i++)
        printf("%2i -> %4i -> %5i\n", i, i * i, i * i * i);
}
