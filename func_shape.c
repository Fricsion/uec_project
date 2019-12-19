#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "img.h"

void img_drawcycloidpoint(struct color c, int a, int dx, int dy, double degree)
{
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

void img_drawcirclepoint(struct color c, int x, int y, int r, double degree)
{
    int x2, y2;
    double radian;
    radian = degree * getPI() / 180.0;
    x2 = r * cos(radian) + x;
    y2 = r * sin(radian) + y;
    img_putpixel(c, x2, y2);
}

void img_drawcircle2(struct color c, int x, int y, int r)
{
    double degree;
    for (degree = 0; degree < 360; degree += 0.1)
    {
        img_drawcirclepoint(c, x, y, r, degree);
    }
}

void img_drawcircle(struct color c, int r)
{
    img_drawcircle2(c, r, 0, 0);
}

void img_fillcircle(struct color c, double x, double y, double r)
{
    int imin = (int)(x - r - 1), imax = (int)(x + r + 1);
    int jmin = (int)(y - r - 1), jmax = (int)(y + r + 1);
    int i, j;
    for (j = jmin; j <= jmax; ++j)
    {
        for (i = imin; i <= imax; ++i)
        {
            if ((x - i) * (x - i) + (y - j) * (y - j) <= r * r)
            {
                img_putpixel(c, i, j);
            }
        }
    }
}

void img_fillrectangle(struct color c, int x1, int y1, int width, int height)
{
    int dx, dy, x, y;
    for (dx = 0; dx <= width; dx++)
    {
        for (dy = 0; dy <= height; dy++)
        {
            x = x1 + dx;
            y = y1 + dy;
            img_putpixel(c, x, y);
        }
    }
}

void img_drawline(struct color c, double a, int b, int x1, int x2)
{
    int y;
    for (; x1 <= x2; x1++)
    {
        y = a * x1 + b;
        img_putpixel(c, x1, y);
    }
}

double getPI()
{
    return M_PI;
}