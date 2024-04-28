#include <iostream>
using std::cout;
using std::endl;

struct Book
{
    char title[100];
    int pages;
    float price;
};

bool isExpensive(Book& b) {
    if (b.price > 1000)
        return true;
    return false;
}

int main() {
    Book LotR = {"Lord of the Rings", 1200, 5500};
    Book HP = {"Harry Potter: The Philosopher's Stone", 300, 900};
    cout << isExpensive(LotR) << endl;
    cout << isExpensive(HP) << endl;
}