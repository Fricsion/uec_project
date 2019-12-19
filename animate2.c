#include "func_shape.h"
#include <math.h>

int main(void)
{
	struct color green = {0, 255, 0};
	struct color red = {255, 0, 0};
	struct color gray = {200, 200, 200};
	struct color white = {255, 255, 255};
	struct color indigo = {29, 49, 86};
	struct color black = {0, 0, 0};
	struct color yellow = {251, 208, 29};
	struct color pink = {255, 192, 203};
	struct color darkred = {153, 51, 51};
	int rad = 30;

	float t;
	for (t = 0.0; t < 4*PI(); t += PI()/10)
	{
		img_clear();

		img_fillrectangle(gray, 0, 0, 300, 100-rad);


		img_fillcircle(indigo, rad * t, 100, rad);

//		img_drawline(black, tan(t), 100, rad * t, rad * t + rad);


		img_drawcycloid3(green, rad, 0, 100-rad, t * 180 / PI());

		img_drawcycloidpoint2(red, rad, 0, 100-rad, t * 180 / PI(), 10);
		img_drawtrochoid2(white, 0, 100-rad, rad, rad*2, t * 180 / PI());

		img_drawtrochoidpoint2(darkred, 0, 100-rad, rad, rad*2, t * 180 / PI(), 5);

		img_drawtrochoid2(pink, 0, 100-rad, rad, rad/2, t * 180 / PI());
		img_drawtrochoidpoint2(darkred, 0, 100-rad, rad, rad/2, t * 180 / PI(), 5);


		img_write();
	}
}
