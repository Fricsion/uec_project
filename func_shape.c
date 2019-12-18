#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "img.h"

void img_drawcycloidpoint(struct color c, int a, int dx, int dy, double degree)
{
    if (a <= 0)
    {
        return;
    }
    int x, y;
    double radian;
    radian = degree * M_PI / 180.0;
    x = a * (radian - sin(radian)) + dx;
    y = a * (1 - cos(radian)) + dy;
    img_putpixel(c, x, y);
}

void img_drawcycloid2(struct color c, int a, int dx, int dy, double num)
{
    double degree;
    for (degree = 0; degree < 360 * num; degree += 0.1)
    {
        img_drawcycloidpoint(c, a, dx, dy, degree);
    }
}

void img_drawcycloid(struct color c, int a, double num)
{
    img_drawcycloid2(c, a, 0, 0, num);
}

void img_drawtrochoidpoint(struct color c, int a, int b, double degree)
{
    if (a <= 0 || a < b)
    {
        return;
    }
    int x, y;
    double radian;
    radian = degree * M_PI / 180.0;
    x = a * radian - b * sin(radian);
    y = a - b * cos(radian);
    img_putpixel(c, x, y);
}

void img_drawtrochoid(struct color c, int a, int b, double num)
{
    double degree;
    for (degree = 0; degree < 360 * num; degree += 0.1)
    {
        img_drawtrochoidpoint(c, a, b, degree);
    }
}

void img_drawcirclepoint(struct color c, int r, int x, int y, double degree)
{
    int x2, y2;
    double radian;
    radian = degree * M_PI / 180.0;
    x2 = r * cos(radian) + x;
    y2 = r * sin(radian) + y;
    img_putpixel(c, x, y);
}

void img_drawcircle2(struct color c, int r, int x, int y)
{
    double degree;
    for (degree = 0; degree < 360; degree += 0.1)
    {
        img_drawcirclepoint(c, r, x, y, degree);
    }
}

void img_drawcircle(struct color c, int r)
{
    img_drawcircle2(c, r, 0, 0);
}