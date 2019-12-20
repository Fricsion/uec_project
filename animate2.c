#include "func_shape.h"
#include <math.h>

int main(void)
{
	struct color green = {0, 255, 0};
	struct color red = {255, 0, 0};
	struct color gray = {200, 200, 200};
	struct color deepbrown = {153, 76, 0};
	struct color white = {255, 255, 255};
	struct color indigo = {29, 49, 86};
	struct color black = {0, 0, 0};
	struct color yellow = {251, 208, 29};
	struct color pink = {255, 192, 203};
	struct color darkred = {153, 51, 51};
	int rad = 18;

	int divx = 300 / 2 - rad * 2 * PI();
	int divy = 100; // レイヤーのずれの値

	float t;
	for (t = 0.0; t <= 10 * PI(); t += PI() / 10)
	{
		img_clear();

//		img_fillRectangle(gray, 0, 0, 300, 100);

		img_fillRectangle(deepbrown, 0, 0, 300, 100);

		// パラメータ変数 t で場合わけ
		if (t <= 4 * PI())
		{
			img_fillCircle(indigo, rad * t + divx, rad + divy, rad);
			img_drawLinePolar(yellow, rad*t +divx, rad +divy, 2*rad, 3*PI()/2-t);
		}
		else if (t <= 5 * PI())
		{
			img_fillCircle(indigo, rad * 4 * PI() + rad * sin(t - 4 * PI()) + divx, rad * cos(t - 4 * PI()) + divy, rad);
			img_drawLinePolar(yellow, rad * 4 * PI() + rad * sin(t - 4 * PI()) + divx, rad * cos(t - 4 * PI()) + divy, rad, 3*PI()/2-t);
		}
		else if (t <= 9 * PI())
		{
			img_fillCircle(indigo, rad * 4 * PI() - rad * (t - 5 * PI()) + divx, -rad + divy, rad);
			img_drawLinePolar(yellow, rad * 4 * PI() - rad * (t - 5 * PI()) + divx, -rad + divy, rad*2, -PI()/2 - t); 
		}
		else if (t <= 10 * PI())
		{
			img_fillCircle(indigo, -rad * sin(t - 9 * PI()) + divx, -rad * cos(t - 9 * PI()) + divy, rad);
			img_drawLinePolar(yellow, -rad * sin(t - 9 * PI()) + divx, -rad * cos(t - 9 * PI()) + divy, rad, -PI()/2 - t);
		}

		if (t <= 12 * PI())
		{
			// サイクロイドの軌跡
			img_drawCycloid3(green, rad, 0 + divx, divy, (t <= 4 * PI()) ? (t * 180 / PI()) : (4 * PI() * 180 / PI()));
			if (t <= 5 * PI())
			{
				img_drawCycloidPoint2(red, rad, 0 + divx, divy, (t <= 4 * PI()) ? (t * 180 / PI()) : (4 * PI() * 180 / PI()), rad / 3);
			}

			// ２倍の動きのトロコイド
			img_drawTrochoid2(white, divx, divy, rad, rad * 2, (t <= 4 * PI()) ? (t * 180 / PI()) : (4 * PI() * 180 / PI()));
			if (t <= 4 * PI())
			{
				img_drawTrochoidPoint2(darkred, divx, divy, rad, rad * 2, (t <= 4 * PI()) ? (t * 180 / PI()) : (4 * PI() * 180 / PI()), rad / 6);
			}

			// 1/2倍の動きのトロコイド
			img_drawTrochoid2(pink, divx, divy, rad, rad / 2, (t <= 4 * PI()) ? (t * 180 / PI()) : (4 * PI() * 180 / PI()));
			if (t <= 4 * PI())
			{
				img_drawTrochoidPoint2(darkred, divx, divy, rad, rad / 2, (t <= 4 * PI()) ? (t * 180 / PI()) : (4 * PI() * 180 / PI()), rad / 6);
			}

			if (t >= 5 * PI())
			{
				// サイクロイドの軌跡
				img_drawCycloidRev(green, rad, 4 * rad * PI() + divx, divy, (t <= 9 * PI()) ? ((t - 5 * PI()) * 180 / PI()) : (4 * PI() * 180 / PI()));
				if (t <= 10 * PI())
				{
					img_drawCycloidPointRev2(red, rad, 4 * rad * PI() + divx, divy, (t <= 9 * PI()) ? ((t - 5 * PI()) * 180 / PI()) : (4 * PI() * 180 / PI()), rad / 3);
				}

				//			// ２倍の動きのトロコイド
				img_drawTrochoidRev(white, rad * 4 * PI() + divx, divy, rad, rad * 2, (t <= 9 * PI()) ? ((t - 5 * PI()) * 180 / PI()) : (4 * PI() * 180 / PI()));
				if (t <= 9 * PI())
				{
					img_drawTrochoidPointRev2(darkred, rad * 4 * PI() + divx, divy, rad, rad * 2, (t - 5 * PI()) * 180 / PI(), rad / 6);
				}

				//			// 1/2倍の動きのトロコイド
				img_drawTrochoidRev(pink, rad * 4 * PI() + divx, divy, rad, rad / 2, (t <= 9 * PI()) ? ((t - 5 * PI()) * 180 / PI()) : (4 * PI() * 180 / PI()));
				if (t <= 9 * PI())
				{
					img_drawTrochoidPointRev2(darkred, rad * 4 * PI() + divx, divy, rad, rad / 2, (t - 5 * PI()) * 180 / PI(), rad / 6);
				}
			}
		}

		img_write();
	}
}
