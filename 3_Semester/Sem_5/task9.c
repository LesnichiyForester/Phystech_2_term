#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFFER_SIZE 1000000

int longest_word(const char str[], char result[])
{
    int templen = 0;
    int maxlen = 0;
    int endcoord;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == ' ' || str[i] == '\n')
        {
            if (templen > maxlen)
            {
                maxlen = templen;
                endcoord = i;
            }
            templen = 0;
        }
        else
            templen += 1;
    }
    for (int i = endcoord - maxlen; i < endcoord; ++i)
        result[i - (endcoord - maxlen)] = str[i];
    return maxlen;
}

int main()
{
    char str[BUFFER_SIZE] ={'('};
    char result[50];
    fgets(str, sizeof(str), stdin);
    longest_word(str, result);
    printf("%s", result);
}