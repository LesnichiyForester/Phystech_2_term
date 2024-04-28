#include <stdio.h>
#include <math.h>

struct point {
    double x, y;
};
typedef struct point Point;

struct triangle {
    Point a, b, c;
};
typedef struct triangle Triangle;

void print_point(Point p) {
    printf("(%f, %f)\n", p.x, p.y);
    return;
};

void print_triangle(Triangle tri) {
    printf("{(%f, %f), (%f, %f), (%f, %f)}\n",
    tri.a.x, tri.a.y, tri.b.x, tri.b.y, tri.c.x, tri.c.y);
    return;
};

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
};

double get_triangle_perimeter (Triangle* const ptri) {
    return distance((*ptri).a, (*ptri).b) + 
           distance((*ptri).b, (*ptri).c) + 
           distance((*ptri).c, (*ptri).a);
};

double get_triangle_area (Triangle* const ptri) {
    double p = get_triangle_perimeter(ptri) / 2;
    return sqrt(p * (p - distance((*ptri).a, (*ptri).b))
                  * (p - distance((*ptri).b, (*ptri).c))
                  * (p - distance((*ptri).c, (*ptri).a)));
};

Triangle moved_triangle(Triangle* const ptri, Point vec) {
    Triangle ntri = {{(*ptri).a.x += vec.x, (*ptri).a.y += vec.y}, 
                     {(*ptri).b.x += vec.x, (*ptri).b.y += vec.y}, 
                     {(*ptri).c.x += vec.x, (*ptri).c.y += vec.y}};
    return ntri;
}

void move_triangle(Triangle tri, Point vec) {
    Triangle ntri = {{tri.a.x += vec.x, tri.a.y += vec.y}, 
                    {tri.b.x += vec.x, tri.b.y += vec.y}, 
                    {tri.c.x += vec.x, tri.c.y += vec.y}};
    tri = ntri;
    return;
};

int main() {
    Point a = {1, 2}, b = {3.2, 4.2}, c = {5.3, 3.3};
    Triangle tri = {a, b, c};
    printf("print_point: ");
    print_point(a);
    printf("print_triangle: ");
    print_triangle(tri);
    printf("distance AB: %f\n", distance(a, b));
    printf("distance BC: %f\n", distance(b, c));
    printf("distance CA: %f\n", distance(c, a));
    printf("perimeter: %f\n", get_triangle_perimeter(&tri));
    printf("area: %f\n", get_triangle_area(&tri));
    Point vec = {7.0, 2.5};
    printf("moved_triangle: ");
    print_triangle(moved_triangle(&tri, vec));
    printf("move_triangle: ");
    move_triangle(tri, vec);
    print_triangle(tri);
}