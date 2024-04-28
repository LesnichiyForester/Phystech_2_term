#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
    int a = 1234;
    int* pa = &a;
    *pa = *pa * 2;

    float b = 1.5;
    float* pb = &b;
    *pb = *pb * *pb;

    char c = 't';
    char* pc = &c;
    *pc = toupper(*pc);

    int array[5] = {10, 20, 30, 40, 50};
    int* par = &array[0];
    *par += 1;
    *(par + 3) += 1;
    for ( ; par != &array[5]; ++par)
        *par += 1;
    
    int brray[5] = {10, 20, 30, 40, 50};
    int* pbr = &brray[3];
    *(pbr - 3) += 1;
    *(pbr + 1) += 1;
    for ( pbr = pbr - 3; pbr != &brray[5]; ++pbr)
        *pbr += 1;

    char str[20] = "sapere aude";
    char* pstr = &str[0];
    *pstr = toupper(*pstr);
    *(pstr + 7) = toupper(*(pstr + 7));
    for (int i = 0; i < 6; ++i)
        *(pstr + i) = toupper(*(pstr + i));
    
    int d = 1234;
    int* pd = &d;
    int** qp = &pd;
    **qp *= 2;


    printf("%i\n%f\n%c\n", a, b, c);
    for (int i = 0; i < 5; ++i)
        printf("%i ", array[i]);
    printf("\n");
    for (int i = 0; i < 5; ++i)
        printf("%i ", brray[i]);
    printf("\n");
    printf("%s\n", str);
    printf("%i\n", d);
}