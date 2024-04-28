#include <stdio.h>

int is_little_endian(){
    int a = 0x112;
    unsigned char* p = (unsigned char*)&a;

    if (*(p) != 0x12)
        return 0;
    if (*(p + 1) != 0x01)
        return 0;
    return 1;
}

int main(){
    int n = 1000
    printf("%i", is_little_endian());
}