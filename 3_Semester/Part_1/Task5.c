#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    int max = INT_MIN;
    int length = 1;
    scanf("%i", &n);
    for (; n != 1; length++)
    {
        printf("%i ", n);
        if (n > max)
            max = n;
        if (n % 2 == 0)
            n = n / 2;
        else
            n = (3 * n) + 1;
    }
    printf("1\nLength = %i, Max = %i", length, max);
}
