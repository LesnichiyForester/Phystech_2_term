#include <stdio.h>

struct book
{
char title[50];
int pages;
float price;
};
typedef struct book Book;

int main()
{
Book b = {"Fahrenheit 451", 400, 700.0};
Book* pb = &b;  //1.a
float* pprice = &b.price;  //1.b
char* pc = &b.title[9];  //1.c

float a = 1.2;  //2
float* p = &a;
float** pp = &p;

Book** ppb = &pb; //3

printf("1.b: %f\n", *pprice);
printf("1.c: %c\n", *pc);
printf("2: %f", **pp);
}

