#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "img.h"

void img_drawcirclepoint(struct color c, int x, int y, int r, double degree)
{
    int x2, y2;
    double radian;
    radian = degree * M_PI / 180.0;
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

void img_drawcycloidpoint(struct color c, int a, int dx, int dy, double degree)
{
    int x, y;
    double radian;
    radian = degree * M_PI / 180.0;
    x = a * (radian - sin(radian)) + dx;
    y = a * (1 - cos(radian)) + dy;
    img_putpixel(c, x, y);
}

void img_drawcycloidpoint2(struct color c, int a, int dx, int dy, double degree, int bold)
{
    int x, y;
    double radian;
    radian = degree * M_PI / 180.0;
    x = a * (radian - sin(radian)) + dx;
    y = a * (1 - cos(radian)) + dy;
    img_fillcircle(c, x, y, bold);
}

void img_drawCycloidPointRev2(struct color c, int a, int dx, int dy, double degree, int bold)
{
    int x, y;
    double radian = degree * M_PI / 180.0;
    x = 300 - a * (radian - sin(radian)) - dx;
    y = -a * (1 - cos(radian)) + dy;
    img_fillcircle(c, x, y, bold);
}

void img_drawCycloidPointRev(struct color c, int a, int dx, int dy, double degree)
{
    img_drawCycloidPointRev2(c, a, dx, dy, degree, 0);
}

void img_drawCycloidRev(struct color c, int a, int dx, int dy, double degree)
{
    double t;
    for (t = 0; t <= degree; t += 0.1)
    {
        img_drawCycloidPointRev(c, a, dx, dy, t);
    }
}

void img_drawcycloid3(struct color c, int a, int dx, int dy, double degree)
{
    double degree2;
    for (degree2 = 0; degree2 <= degree; degree2 += 0.1)
    {
        img_drawcycloidpoint(c, a, dx, dy, degree2);
    }
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

void img_drawtrochoidpoint2(struct color c, int dx, int dy, int a, int b, double degree, int bold)
{
    if (a <= 0)
    {
        return;
    }
    int x, y;
    double radian;
    radian = degree * M_PI / 180.0;
    x = a * radian - b * sin(radian) + dx;
    y = a - b * cos(radian) + dy;
    img_fillcircle(c, x, y, bold);
}
void img_drawtrochoidpoint(struct color c, int a, int b, double degree)
{
    img_drawtrochoidpoint2(c, 0, 0, a, b, degree, 0);
}

void img_drawtrochoid2(struct color c, int x, int y, int a, int b, double degree)
{
    double degree2;
    for (degree2 = 0; degree2 <= degree; degree2 += 0.1)
    {
        img_drawtrochoidpoint2(c, x, y, a, b, degree2, 0);
    }
}

void img_drawtrochoid(struct color c, int a, int b, double num)
{
    double degree;
    for (degree = 0; degree < 360 * num; degree += 0.1)
    {
        img_drawtrochoidpoint(c, a, b, degree);
    }
}

void img_drawTrochoidPointRev2(struct color c, int dx, int dy, int a, int b, double degree, int bold)
{
    if (a <= 0)
    {
        return;
    }
    int x, y, X, Y;
    double radian;
    radian = degree * M_PI / 180.0;
    x = a * radian - b * sin(radian);
    y = a - b * cos(radian);
    X = -x + dx;
    Y = -y + dy;
    img_fillcircle(c, X, Y, bold);
}

void img_drawTrochoidPointRev(struct color c, int dx, int dy, int a, int b, double degree)
{
    img_drawTrochoidPointRev2(c, dx, dy, a, b, degree, 0);
}

void img_drawTrochoidRev(struct color c, int x, int y, int a, int b, double degree)
{
    double t;
    for (t = 0; t <= degree; t += 0.1)
    {
        img_drawTrochoidPointRev(c, x, y, a, b, t);
    }
}

double PI()
{
    return M_PI;
}
double PI_2()
{
    return M_PI_2;
}
double PI_4()
{
    return M_PI_4;
}
