#include <stdio.h>

int main(){
    int a = 0x11223344;
    int b = 65535;
    int c = -1;
    int array[3] = {10, 2000, 65535};
    char str[8] = "Hello";
    float x = 1.0f;

    FILE* ft = fopen("task1ans.txt", "w");

    unsigned char* p = (unsigned char*)&a;
    for (size_t i = 0; i < sizeof(a); i++)
        fprintf(ft, "%.2x ", *(p + i));
    fprintf(ft, "\n");
    p = (unsigned char*)&b;
    for (size_t i = 0; i < sizeof(b); i++)
        fprintf(ft, "%.2x ", *(p + i));
    fprintf(ft, "\n");
    p = (unsigned char*)&c;
    for (size_t i = 0; i < sizeof(c); i++)
        fprintf(ft, "%.2x ", *(p + i));
    fprintf(ft, "\n");
    p = (unsigned char*)&array;
    for (size_t i = 0; i < sizeof(array); i++)
        fprintf(ft, "%.2x ", *(p + i));
    fprintf(ft, "\n");
    p = (unsigned char*)&str;
    for (size_t i = 0; i < sizeof(str); i++)
        fprintf(ft, "%x ", *(p + i));
    fprintf(ft, "\n");
    p = (unsigned char*)&x;
    for (size_t i = 0; i < sizeof(x); i++)
        fprintf(ft, "%x ", *(p + i));
    fprintf(ft, "\n");
}