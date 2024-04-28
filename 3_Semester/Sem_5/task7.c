#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFFER_SIZE 1000000


int main()
{
    char str[BUFFER_SIZE];
    scanf ("%s", str);
    int ans = 1;
    int len = -1;
    for (int i = 0; str[i] != '\0'; i++)
        len += 1;
    for (int i = 0; i < (len - len % 2) / 2; i++)
        if (str[i] != str[len - i])
            ans = 0;
    if (ans)
        printf("Yes");
    else
        printf("No");
}