#include <iostream>

namespace mipt {
    int a = 100;

    void func() {
        printf("Hello World!\n");
    }
};

int main() {
    printf("%i", mipt::a);
}