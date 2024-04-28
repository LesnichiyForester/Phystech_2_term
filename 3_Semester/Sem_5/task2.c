#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int a;
    scanf("%c", &a);
    if (islower(a))
        printf("%i", a - 'a' + 1);
    else if (isupper(a))
        printf("%i", a - 'A' + 1);
    else
        printf("Not a letter");
}