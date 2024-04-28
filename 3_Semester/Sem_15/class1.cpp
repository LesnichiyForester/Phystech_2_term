#include <iostream>
#include <string>

#include "book.h"
#include "complex.h"

using std::cout, std::endl;
using namespace std::string_literals;

template <typename T>
void PrintParentheses(const T& a) {
    cout << '(' << a << ')' << endl;
}

int main() 
{
    
    cout << 3 << endl;


    mipt::Complex a {4, 2};
    cout << a << endl;

    Book b {"Harry Potter", 500, 400.0};
    cout << b << endl;

    PrintParentheses(5);
    PrintParentheses(a);
    PrintParentheses(b);

}
