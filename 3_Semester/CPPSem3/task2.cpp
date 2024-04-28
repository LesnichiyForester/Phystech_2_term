#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

string repeat1(const string& s) {
    return s + s;
}

void repeat2(string& s) {
    s += s;
}

void repeat3(string* ps) {
    *ps += *ps;
}

string* repeat4(const string& s) {
    string* ps = new string(s + s);
    return ps;
}

int main() {
    string str1 = "Cat";
    
    cout << repeat1(str1) << endl;
    
    repeat2(str1);
    cout << str1 << endl;

    str1 = "Cat";
    
    repeat3(&str1);
    cout << str1 << endl;

    str1 = "Cat";
    
    string* pstr = repeat4(str1);
    cout << *pstr << endl;
    
    delete pstr;
    

}