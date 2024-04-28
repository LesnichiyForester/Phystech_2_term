#include <stdio.h>
#include <limits.h>

int main()
{
    int a[1000];
    int n;
    scanf("%i", &n);
    for (int i = 1; i < n + 1; i++)
        scanf("%i", &a[i]);

    a[n + 1] = INT_MIN;
    a[0] = INT_MIN;
    int i = 0;
    for (int step = n; (a[i - 1] > a[i]) || (a[i + 1] > a[i]); i = i + step)
    {
        if (step == 0)
            step = 2;
        if (a[i + 1] > a[i])
            step = step / 2;
        else
            step = - step / 2;
    }
    printf("%i", a[i]);
}
