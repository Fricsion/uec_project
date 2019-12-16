#define _USE_MATH_DEFINES
#include "img.h"

/*
* サイクロイドの1点描く関数
* {struct color c}: サイクロイドの色
* {int a}: 転がす円の半径 (a>0)
* {double degree}: 角度 (*周期2πで孤を一つ作る)
*/
void img_fillcycloidpoint(struct color c, int a, double degree);

/*
* サイクロイドを描く関数
* {struct color c}: サイクロイドの色
* {int a}: 転がす円の半径 (a>0)
*/
void img_fillcycloid(struct color c, int a);