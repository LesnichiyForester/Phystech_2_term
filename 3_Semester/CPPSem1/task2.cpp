#include <iostream>
using std::cout;
using std::endl;

int cubeV(const int a) {
    return a * a * a;
}

int main() {
    int a = 3;
    int a3 = cubeV(a);
    cout << a3 << endl;
}