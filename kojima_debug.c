//小島デバック用
#include "func_shape.h"
#include <math.h>
#define PI 3.14159265358979

int main(void)
{
    struct color c1 = {30, 255, 0};
    int i;
        img_clear();
        img_fillcycloid(c1, 20);
        img_write();
}
