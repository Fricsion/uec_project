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
	int rad = 15;

	int divx = 300 / 2 - rad*2*PI(); int divy = 100; // レイヤーのずれの値

	float t;
	for (t = 0.0; t <= 10*PI(); t += PI()/10)
	{
		img_clear();

		img_fillrectangle(gray, 0, 0, 300, 100);


		// パラメータ変数 t で場合わけ
		if(t <= 4*PI()) {
			img_fillcircle(indigo, rad * t +divx, rad +divy, rad);
		} else if(t <= 5*PI()) {	
			img_fillcircle(indigo, rad * 4*PI() + rad * sin(t-4*PI()) +divx,  rad * cos(t-4*PI()) +divy, rad);
		} else if(t <= 9*PI()) {
			img_fillcircle(indigo, rad * 4*PI()  - rad * (t - 5*PI()) +divx, -rad +divy, rad);
		} else if(t <= 10*PI()) {
			img_fillcircle(indigo,  - rad * sin(t-9*PI()) +divx, - rad * cos(t-9*PI()) +divy, rad);
		}

		if(t <= 10*PI()) {
			// サイクロイドの軌跡
			img_drawcycloid3(green, rad, 0 +divx, divy, t * 180 / PI());
			img_drawcycloidpoint2(red, rad, 0 +divx, divy, t * 180 / PI(), rad/3);

			// ２倍の動きのトロコイド
			img_drawtrochoid2(white, 0 +divx, divy, rad, rad*2, t * 180 / PI());
			img_drawtrochoidpoint2(darkred, 0 +divx, divy, rad, rad*2, t * 180 / PI(), rad/6);

			// 1/2倍の動きのトロコイド
			img_drawtrochoid2(pink, 0 +divx, divy, rad, rad/2, t * 180 / PI());
			img_drawtrochoidpoint2(darkred, 0 +divx, divy, rad, rad/2, t * 180 / PI(), rad/6);

			if(t >= 5*PI()) {
				// サイクロイドの軌跡
				img_drawCycloidRev(green, rad, divx, divy, (t-5*PI()) * 180 / PI());
				img_drawCycloidPointRev2(red, rad, divx, divy, (t-5*PI()) * 180 / PI(), rad/3);

				//			// ２倍の動きのトロコイド
				img_drawTrochoidRev(white, 0 +divx, divy, rad, rad*2, (t-5*PI()) * 180 / PI());
				img_drawTrochoidPointRev2(darkred, 0 +divx, divy, rad, rad*2, (t-5*PI()) * 180 / PI(), rad/6);

				//			// 1/2倍の動きのトロコイド
				img_drawTrochoidRev(pink, 0 +divx, divy, rad, rad/2, (t-5*PI()) * 180 / PI());
				img_drawTrochoidPointRev2(darkred, 0 +divx, divy, rad, rad/2, (t-5*PI()) * 180 / PI(), rad/6);

			}

		}

		img_write();
	}
}
