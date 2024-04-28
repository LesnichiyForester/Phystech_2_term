#include <iostream>

namespace myspace {
void printNTimes(const char* str, int n=10) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; str[j] != '\0'; j++)
            std::cout << str[j];
        std::cout << std::endl;
    }
}
};

int main() {
    char  str[1000];
    std::cin >> str;
    myspace::printNTimes(str, 10);
}