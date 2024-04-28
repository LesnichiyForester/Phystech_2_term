#include <stdio.h>
struct Point {
double x, y;
};
void print_point(struct Point a) {
printf("(%d, %d)", a.x, a.y);
}
struct Point add_points(struct Point a, struct Point b) {
struct Point result;
result.x = a.x + b.x;
result.y = a.y + b.y;
return result;
}
int main() {
struct Point a = {2.1, 4.3}, b = {6.7, 8.9};
struct Point c = add_points(a, b);
print_point(a);
}