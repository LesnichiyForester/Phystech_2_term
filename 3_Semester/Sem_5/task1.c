#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int a;
    scanf("%c", &a);
    if (isupper(a))
        printf("Uppercase Letter");
    else if (islower(a))
        printf("Lowercase Letter");
    else if (isdigit(a))
        printf("Digit");
    else
        printf("Other");
}