#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "img.h"

void img_fillcycloidpoint(struct color c, int a, double degree)
{
    if (a <= 0)
    {
        return;
    }
    int x, y;
    double radian;
    radian = degree * M_PI / 180.0;
    x = a * (radian - sin(radian));
    y = a * (1 - cos(radian));
    img_putpixel(c, x, y);
}

void img_fillcycloid(struct color c, int a)
{
    double degree;
    for (degree = 0; degree < 360 * 10; degree += 0.1)
    {
        img_fillcycloidpoint(c, a, degree);
    }
}