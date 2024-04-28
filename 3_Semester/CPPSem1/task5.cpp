#include <iostream>
using std::cout;
using std::endl;

struct Book
{
    char title[100];
    int pages;
    float price;
};

void addPrice(Book& b, float x) {
    b.price += x;
}

int main() {
    Book b = {"Lord of the Rings", 1200, 5.5};
    float x = 1.25;
    addPrice(b, x);
    cout << b.price << endl;
}