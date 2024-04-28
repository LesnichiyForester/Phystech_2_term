#include <stdio.h>

int main()
{
    int a[1000];
    int n;
    int x;
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
        scanf("%i", &a[i]);
    scanf("%i", &x);

    int r = n, l = -1;
    if (a[n - 1] < x)
    {
        printf("%i", n);
        return 0;
    }
    for (int mid = 0; r > l + 1; )
    {
        mid = (l + r) / 2;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid;
    }
    printf("%i", a[r]);
}
