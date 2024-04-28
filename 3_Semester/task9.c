#include <stdio.h>


struct book
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

void polyprint (const char* type, void* p)
{
    int len = 0;
    str
    for (len = 0; type[len] = "\0"; ++len)
};

int main()
{
    int a = 123;
    polyprint("Integer", &a);
    float b = 1.5;
    polyprint("Float", &b);
    char c = 'T';
    polyprint("Character", &c);
    Book d = {"War and Peace", 1200, 900.0};
    polyprint("Book", &d);
    char e[] = "Sapere Aude";
    polyprint("String", e);
    int f[] = {10, 20, 30, 40, 50};
    polyprint("IntegerArray 5", f);
}