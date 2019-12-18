#define _USE_MATH_DEFINES
#include "img.h"

/*
* サイクロイドの1点描く関数
* {struct color c}: サイクロイドの色
* {int a}: 転がす円の半径 (a>0)
* {double degree}: 角度 (*周期2πで孤を一つ作る)
*/
void img_drawcycloidpoint(struct color c, int a, double degree);

/*
* サイクロイドを描く関数
* {struct color c}: サイクロイドの色
* {int a}: 転がす円の半径 (a>0)
* {double num}: 孤を何個生成するか
*/
void img_drawcycloid(struct color c, int a, double num);

/*
* トロコイドの1点描く関数
* {struct color c}: トロコイドの色
* {int a}: 転がす円の半径 (a>0)
* {int b}: 円の中心から奇跡を描く点Pまでの距離 (a > b > 0)
* {double degree}: 角度 (*周期2πで孤を一つ作る)
*/
void img_drawtrochoidpoint(struct color c, int a, int b, double degree);

/*
* トロコイドを描く関数
* {struct color c}: トロコイドの色
* {int a}: 転がす円の半径 (a>0)
* {int b}: 円の中心から奇跡を描く点Pまでの距離 (a > b > 0)
* {double num}: 孤を何個生成するか
*/
void img_drawtrochoid(struct color c, int a, int b, double num);