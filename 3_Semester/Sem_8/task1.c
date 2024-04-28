#include <stdio.h>
#include <stdlib.h>

struct book 
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

int main(){
    long long* p1 = (long long*)malloc(sizeof(long long));  //1
    *p1 = 123;

    char* p2 = (char*)malloc(sizeof(char) * 100);  //2
    char tempstr1[100] = "Elephant";
    p2[0] = tempstr1[0];
    for (int i = 1; tempstr1[i - 1] != '\0'; i++)
        p2[i] = tempstr1[i];

    char* pp3 = (char*)malloc(sizeof(char*));  //3
    char* p3 = (char*)malloc(sizeof(char) * 100);
    pp3 = p3;
    char tempstr2[100] = "Cats and Dogs";
    pp3[0] = tempstr2[0];
    for (int i = 1; tempstr2[i - 1] != '\0'; i++)
       pp3[i] = tempstr2[i];

    Book* pb = (Book*)malloc(sizeof(char) * 50 + sizeof(int) + sizeof(float));  //4
    pb->pages = 1000;
    pb->price = 750.0;
    tempstr1 = "Don Quixote";
    strcpy(pb->title[0], tempstr1);
    for (int i = 1; pb->title[i - 1] != '\0'; i++)
       pb->title[i] = tempstr1;

    char* pp5 = (char*)malloc(sizeof(char*));  //5
    char* p5 = (char*)malloc(sizeof(char) * 50);
    Book b = {"Don Quixote", 1000, 750.0};
    pp5 = p5;
    pp5[0] = b.title[0];
    for (int i = 1; b.title[i - 1] != '\0'; i++)
       pp5[i] = b.title[i];

    char* pp6 = (char*)malloc(sizeof(char*));  //6
    char* p6 = (char*)malloc(sizeof(char) * 50);
    pp6 = p6;
    pp6[0] = b.title[0];
    for (int i = 1; b.title[i - 1] != '\0'; i++)
       pp6[i] = b.title[i];


    printf("1: %lli\n2: ", *p1);
    for (int i = 0; p2[i] != '\0'; i++)
        printf("%c", p2[i]);
    printf("\n3: ");
    for (int i = 0; pp3[i] != '\0'; i++)
        printf("%c", pp3[i]);
    printf("\n4: ");
    for (int i = 0; pb[i] != '\0'; i++)
        printf("%c", pb[i]);
    printf("\n5: ");

    printf("\n6: ");
    for (int i = 0; pp6[i] != '\0'; i++)
        printf("%c", pp6[i]);
    printf("\n7: ");

    free(p1);
    free(p2);
    free(p3);
    free(pp3);
    free(pb);
    free(p6);
    free(pp6);
}