#include <stdio.h>
#include <string.h>

int main() {
    unsigned char a[8] = {0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80};
    memcpy(a, a + 3, 5);
    for (int i = 0; i < 8; i++)
        printf("%02x ", a[i]);
}
