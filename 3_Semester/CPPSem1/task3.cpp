#include <iostream>
using std::cout;
using std::endl;

int cubeV(const int* pa) {
    return *pa * *pa * *pa;
}

int main() {
    int a = 3;
    int* pa = &a;
    int a3 = cubeV(pa);
    cout << a3 << endl;
}