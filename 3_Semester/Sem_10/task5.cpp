#include <iostream>

struct Book {
    char title[100];
    int pages;
    float price;
};
typedef struct Book book;

void addPrice(book* bo, int pricechange) {
    (*bo).price = (*bo).price + pricechange;
};

int main() {
    book bo = {"Lord of The Rings", 2500, 100};
    addPrice(&bo, 20);
    std::cout << bo.price << std::endl;
}