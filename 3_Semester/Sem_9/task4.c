#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct color
{
    unsigned char r, g, b;
};
typedef struct color Color;


int main()
{
    Color data[240000] = {0};
    for (int i = 0; i < 240000; i++) {
        //printf("%i: %f\n", i, pow((i - ((i / 600) * 600)) - 300, 2) + pow(((- i) / 600) + 200, 2));
        if (pow((i - ((i / 600) * 600)) - 300, 2) + pow(((- i) / 600) + 200, 2) < 121 * 120) {
            //printf("red");
            data[i].r = 190;
            data[i].g = 0;
            data[i].b = 41;
        }
        else {
            data[i].r = 255;
            data[i].g = 255;
            data[i].b = 255;
        }
    }

    
    // Сохраняем картинку в текстовом формате
    FILE* ft = fopen("Japan.ppm", "w");
    fprintf(ft, "P3\n600 400\n255\n");
    for (int i = 0; i < 240000; i++)
    {
        fprintf(ft, "%i %i %i\n", data[i].r, data[i].g, data[i].b);
    }
    fclose(ft);
}