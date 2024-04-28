#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFFER_SIZE 1000000


int main()
{
    char str[BUFFER_SIZE];
    scanf ("%s", str);
    int count_open = 0, count_close = 0;
    int check = 1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
            count_open += 1;
        else
            count_close += 1;
        if (count_close > count_open)
        {
            printf("No");
            check = 0;
            break;
        }
    }
    if (check == 1)
        if (count_close == count_open)
            printf("Yes");
        else
            printf("No");
}