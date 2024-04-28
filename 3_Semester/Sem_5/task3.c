#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFFER_SIZE 1000000


int main()
{
    char str[BUFFER_SIZE];
    scanf ("%s", str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int j = 0; j < i + 1; j++)
            printf("%c", str[j]);
        printf("\n");
    }
}