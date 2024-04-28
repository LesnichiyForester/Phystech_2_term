#include <iostream>
using std::cout;
using std::endl;

namespace myspace {
    void printNTimes(const char* str, int n=10) {
        for (int i = 0; i < n; i++) {
            cout << str << endl;
        }
    }
}

int main() {
    myspace::printNTimes("Str Straholud", 2);
}