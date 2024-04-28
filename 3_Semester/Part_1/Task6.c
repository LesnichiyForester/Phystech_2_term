#include <stdio.h>
#include <limits.h>

int main()
{
    int a, b;
    scanf("%i %i", &a, &b);
    int max = INT_MIN;
    int length = 1;
    int ans;

    for (int n = a; n <= b; n++)
    {
        for (int c = n; c != 1; length++)
        {
            if (c % 2 == 0)
                c = c / 2;
            else
                c = (3 * c) + 1;
        }
        if (length > max)
        {
            max = length;
            ans = n;
        }
        length = 1;
    }
    printf("%i %i", ans, max);
}
