#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFFER_SIZE 1000000


int main()
{
    char str[BUFFER_SIZE];
    fgets(str, sizeof(str), stdin);
    for (int i = 0; str[i] != '\n'; i++)
    {
        if (isblank(str[i + 1]) || str[i + 1] == '\n')
            printf("%c!", str[i]);
        else
            printf("%c", str[i]);
    }
}