#include <stdio.h>
#include <string.h>

int main()
{
    int a = 1234;
    int* pa = &a;
    double b = 12.34;
    double* pb = &b;
    char c = ')';
    char* pc = &c;
    int array[5] = {10, 20, 30, 40, 50};
    int* par = &array[0];
    char str[20] = "Sapere Aude";
    char* pstr = &str[7];
}