#include <stdio.h>
struct date 
{
    int day, month, year;
};
typedef struct date Date;

struct movie 
{
    char title[50];
    float rating;
    Date release_date;
};
typedef struct movie Movie;


int main() 
{
    Date a1 = {15, 5, 1970};  //4.1
    Date* p1 = &a1;
    p1->year += 1;
    printf("%d %d %d\n", 
           a1.day, a1.month, a1.year);

    Movie a2 = {"Inception", 8.661, {8, 6, 2010}};  //4.2
    Movie* p2 = &a2;
    p2->rating += 1;
    p2->release_date.month += 1;
    printf("rating: %f\ndate: %i\n", p2->rating, p2->release_date.month);

    Movie array[3] = {{"Inception", 8.661, {8, 6, 2010}},
                      {"Green Mile", 9.062, {6, 12, 1999}},
                      {"Leon", 8.679, {14, 9, 1994}}};
    Movie* p3 = &array[1];
    (p3 - 1)->rating += 1;
    (p3 + 1)->release_date.year *= 2;
    printf("rating: %f\ndate: %i\n", (p3 - 1)->rating, (p3 + 1)->release_date.year);
}