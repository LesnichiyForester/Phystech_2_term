#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void cut(string& str) {
    size_t dot = str.find('.');
    if (dot != string::npos) {
        str.erase(dot);
        str.shrink_to_fit();
    } 
    else {
        str.clear();
        str.shrink_to_fit();
    }
}

int main() {
    string s1 = "cat.dog.mouse.elephant.lion.crocodile";
    cut(s1);
    cout << s1 << endl;
    s1 = "";
    cut(s1);
    cout << s1 << endl;
}
