#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFFER_SIZE 1000000

void encrypt(char* str, int k)
{
    for (int i = 0; str[i] != '\n'; ++i)
    {
        str[i] = str[i] + k;
        if (str[i] > 'z')
            str[i] = str[i] - 'z' + 'a' - 1;
    }
    printf("%s", str);
    return;
}

int main()
{
    int k;
    int temp = 0;
    char str[BUFFER_SIZE];
    scanf("%i\n", &k);
    fgets(str, sizeof(str), stdin);
    encrypt(str, k);
}