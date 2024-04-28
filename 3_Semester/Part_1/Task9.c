#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    int duble = 1;
    scanf("%i", &n);

    for (int a = 1; a <= n; a++)
        for (int b = a; b <= n; b++)
            for (int c = b; c <= n; c++)
                if (a * a + b * b == c * c)
                {
                    for (int i = 2; i <= n / 2; i++)
                        if (a % i == 0 && b % i == 0 && c % i == 0)
                            duble = 0;
                    if (duble)
                        printf("%i %i %i\n", a, b, c);
                    duble = 1;
                }
}
