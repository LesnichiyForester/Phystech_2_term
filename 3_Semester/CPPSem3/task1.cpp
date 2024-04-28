#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

string change_case(const string& str) {
    if (str.empty()) {
        return str;
    }
    string res = str;
    if (res[0] >= 'a' && res[0] <= 'z') {
        res[0] -= 'a' - 'A';
    } else if (res[0] >= 'A' && res[0] <= 'Z') {
        res[0] += 'a' - 'A';
    }
    return res;
}


int main() {
    cout << change_case("Cat") << endl;
    cout << change_case("dog") << endl;
    cout << change_case("") << endl;
}