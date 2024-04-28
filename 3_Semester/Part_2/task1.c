#include <stdio.h>

int main()
{
    int a[1000];
    int alta[1000];
    int n;
    int altn;
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
        scanf("%i", &a[i]);

    printf("Subtask 1: Doubling of array\n"); // Subtask 1: Doubling of array
    for (int i = 0; i < n; i++)
        alta[i] = a[i];
    for (int i = 0; i < n; i++)
        alta[n + i] = alta[i];
    altn = 2 * n;
    for (int i = 0; i < altn; i++)
        printf("%i ", alta[i]);
    printf("\n");

    printf("Subtask 2: Insert\n"); // Subtask 2: Insert
    for (int i = 0; i < n; i++)
        alta[i] = a[i];
    int b;
    int k;
    scanf("%i %i", &b, &k);
    for (int i = n; i > k; i--)
        alta[i + 1] = alta[i];
    alta[k + 1] = b;
    altn = n + 1;
    for (int i = 0; i < altn; i++)
        printf("%i ", alta[i]);
    printf("\n");
    
    printf("Subtask 3: Deletion\n"); // Subtask 3: Deletion
    for (int i = 0; i < n; i++)
        alta[i] = a[i];
    scanf("%i", &k);
    for (int i = k; i < n - 1; i++)
        alta[i] = alta[i + 1];
    altn = n - 1;
    for (int i = 0; i < altn; i++)
        printf("%i ", alta[i]);
    printf("\n");

    printf("Subtask 4: Subarray deletion\n"); // Subtask 4: Subarray deletion
    for (int i = 0; i < n; i++)
        alta[i] = a[i];
    int m;
    scanf("%i %i", &k, &m);
    for (int i = k; i < n - 1; i++)
        alta[i] = alta[i + m - k + 1];
    altn = n - (m - k) - 1;
    for (int i = 0; i < altn; i++)
        printf("%i ", alta[i]);
    printf("\n");

    printf("Subtask 5: Negative numbers deletion\n"); // Subtask 5: Negative numbers deletion
    for (int i = 0; i < n; i++)
        alta[i] = a[i];
    int totdel = 0;
    int inarow = 0;
    for (int i = 0; i < n - totdel; i++)
    {
        if (alta[i] >= 0)
        {
            alta[i - inarow - totdel] = alta[i];
            totdel += inarow;
            inarow = 0;
        }
        else
            inarow += 1;
    }
    altn = n - totdel - 1;
    for (int i = 0; i < altn; i++)
        printf("%i ", alta[i]);
    printf("\n");

    printf("Subtask 6: Odd/even separation\n"); // Subtask 6: Odd/even separation
    for (int i = 0; i < n; i++)
        alta[i] = a[i];
    int temp = 0;
    int end = 0;
    int oddseq = 0;
    for (int i = 0; i < n - oddseq - 1; i++)
        if (alta[i] % 2 == 0)
        {
            for (int j = n - oddseq - 1; end == 0; j--)
                if (alta[j] % 2 != 0)
                {
                    temp = alta[j];
                    alta[j] = alta[i];
                    alta[i] = temp;
                    oddseq = n - oddseq - j;
                    end = 1;
                }
            end = 0;
        }
    altn = n;
    for (int i = 0; i < altn; i++)
        printf("%i ", alta[i]);
    printf("\n");

    printf("Subtask 7: Doubling of array the other way\n"); // Subtask 7: Doubling of array the other way
    for (int i = 0; i < n; i++)
        alta[i] = a[i];
    for (int i = 2 * n + 1; i > 0; i -= 2)
    {
        alta[i] = alta[i / 2];
        alta[i - 1] = alta[i];
    }
    altn = 2 * n;
    for (int i = 0; i < altn; i++)
        printf("%i ", alta[i]);
    printf("\n");

    printf("Subtask 8: Cycled shift\n"); // Subtask 7: Cycyled Shift
    scanf("%i", &k);
    for (int i = 0; i < n; i++)
        alta[i] = a[i];
    for (int i = n - 1; i > k - 1; i--)
    {
        temp = alta[i];
        alta[i] = alta[i - k];
        alta[i - k] = temp;
    }
    altn = n;
    for (int i = 0; i < altn; i++)
        printf("%i ", alta[i]);
    printf("\n");
}
