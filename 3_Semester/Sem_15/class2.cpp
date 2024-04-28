#include <iostream>
#include <string>
using namespace std::string_literals;
using std::cout;
using std::endl;

template <typename T>
T triple(const T& a) {
    return a * 3;
}

std::string triple(const std::string& a) {
    return a + a + a;
}

int main() 
{
    int a = 5;
    std::string b = "adf"s;
    cout << triple(a) << endl;
    cout << triple(b) << endl;

}