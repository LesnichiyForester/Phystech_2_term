#include <stdio.h>

int main()
{
    int a[1000];
    int sums[1000];
    int n, m;
    scanf("%i %i", &n, &m);
    for (int i = 0; i < n * m; i++)
        scanf("%i", &a[i]);
    for (int i = 0; i < m; i++)
        sums[i] = 0;

    for (int i = 0; i < m; i++)
        for (int j = i; j < (n - 1) * m + i + 1; j += m)
        {
            sums[i] += a[j];
            printf("%i %i\n", i, j);
        }
    for (int i = 0; i < m; i++)
        printf("%i ", sums[i]);
    printf("\n");
}
