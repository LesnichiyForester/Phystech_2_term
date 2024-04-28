#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

string operator*(const string& s, int n) {
    string res;
    for (int i = 0; i < n; i++) {
        res += s;
    }
    return res;
}

int main() {
    string str = "Cat";
    
    cout << str * 3 << endl;
}
