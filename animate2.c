#include "func_shape.h"
#include <math.h>

int main(void)
{
	struct color green = {0, 255, 0};
	struct color red = {255, 0, 0};
	struct color gray = {200, 200, 200};
	struct color white = {255, 255, 255};
	int rad = 50;

	float t;
	for (t = 0.0; t < 2*PI(); t += PI()/10)
	{
		img_clear();

		img_drawcycloidpoint(green, rad, 0, 50, t);

		img_drawcircle2(gray, rad * t, 100, rad);

		img_write();
	}
}
