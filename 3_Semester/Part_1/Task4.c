#include <stdio.h>
#include <limits.h>

int main() // all 4 subtasks are in this code
{
    int n;
    scanf("%i", &n);
    int min = INT_MAX;
    int max = INT_MIN;
    int odd_max = INT_MIN;
    int even_min = INT_MAX;
    int ans_odd_max = 1, ans_even_min = 1;
    int occur = 0;
    int last;
    int ans_4 = 3;
    int check = 3;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%i", &a);

        if (a < min) // Subtask 1
            min = a;

        if (a > odd_max && a % 2 == 1) // Subtask 2
        {
            odd_max  = a;
            ans_odd_max = 0;
        }
        if (a < even_min && a % 2 == 0)
        {
            even_min  = a;
            ans_even_min = 0;
        }

        if (a == max) // Subtask 3
            occur += 1;
        if (a > max)
        {
            max = a;
            occur = 1;
        }

        if (i) // Subtask 4
        {
            if (check == 3)
            {
                if (a == last)
                    check = ans_4 = 0;
                if (a > last)
                    check = ans_4 = 1;
                if (a < last)
                    check = ans_4 = 2;
            }
            if (check == 0)
                if (a != last)
                {
                    check = 4;
                    ans_4 = 3;
                }
            if (check == 1)
                if (a <= last)
                {
                    check = 4;
                    ans_4 = 3;
                }
            if (check == 2)
                if (a >= last)
                {
                    check = 4;
                    ans_4 = 3;
                }
        }
        last = a;
    }

    printf("Subtask 1:\n%i\n", min);
    if (ans_even_min)
        printf("Subtask 2:\nNone %i\n", odd_max);
    else if (ans_odd_max)
        printf("Subtask 2:\n%i None\n", even_min);
    else
        printf("Subtask 2:\n%i %i\n", even_min, odd_max);
    printf("Subtask 3:\n%i %i\n", max, occur);
    printf("Subtask 4:\n");
    if (ans_4 == 0)
        printf("Equal\n");
    else if (ans_4 == 1)
        printf("Increasing\n");
    else if (ans_4 == 2)
        printf("Decreasing\n");
    else if (ans_4 == 3)
        printf("None\n");
}
