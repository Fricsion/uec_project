#include "func_shape.h"
#include <math.h>
#define PI 3.14159265358979

int main(void) {
	struct color green = {0, 255, 0};
	struct color red = {255, 0, 0};
	struct color gray = {200, 200, 200};
	int rad = 50;
	
	int i;
	for(i = 0; i < 30; i++) {
		img_clear();
		img_fillcircle(gray, i, 100, rad);
		img_fillcycloid(green, rad, 5);
		img_filltrochoid(red, rad, rad-100, 3);

		img_write();
	}

}
