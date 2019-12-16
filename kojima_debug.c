//小島デバック用
#include "func_shape.h"
#include <math.h>
#define PI 3.14159265358979

int main(void)
{
    struct color c1 = {30, 255, 0};
    struct color c2 = {255, 0, 0};
    int i;
    img_clear();
    img_fillcycloid(c1, 10, 10);
    img_filltrochoid(c2, 10, 5, 10);
    img_write();
}
