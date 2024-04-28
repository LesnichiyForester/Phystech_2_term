#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFFER_SIZE 1000000


int main()
{
    char str1[BUFFER_SIZE], str2[BUFFER_SIZE];
    scanf ("%s %s", str1, str2);
    int i;
    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
        printf("%c%c", str1[i], str2[i]);
    if (str1[i] == '\0')
        for (i = i; str2[i] != '\0'; i++)
            printf("%c", str2[i]);
    else
        for (i = i; str1[i] != '\0'; i++)
            printf("%c", str1[i]);

}