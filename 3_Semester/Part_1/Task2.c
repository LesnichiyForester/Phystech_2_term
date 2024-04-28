#include <stdio.h>

int main()
{
    int a, b, c;
    int crit;
    crit = 1;
    scanf("%i %i %i", &a, &b, &c);
    if (a == b && b == c)
    {
        printf("Equal ");
        crit = 0;
    }
    if ((b == (a + 1) && c == (b + 1)) || (b == (a - 1) && c == (b - 1)))
    {
        printf("Consecutive ");
        crit = 0;
    }
    if (a < b && b < c)
    {
        printf("Increasing ");
        crit = 0;
    }
    if (a > b && b > c)
    {
        printf("Decreasing ");
        crit = 0;
    }
    if (crit)
        printf("None");
    printf("\n");
}
