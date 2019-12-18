#define _USE_MATH_DEFINES
#include "img.h"

/*
* サイクロイドの1点描く関数
* {struct color c}: サイクロイドの色
* {int a}: 転がす円の半径 (a>0)
* {int dx}: x軸方向に平行移動する量
* {int dy}: y軸方向に平行移動する量 
* {double degree}: 角度 (*周期2πで孤を一つ作る)
*/
void img_drawcycloidpoint(struct color c, int a, int dx, int dy, double degree);

/*
* サイクロイドを描く関数 (平行移動ver)
* {struct color c}: サイクロイドの色
* {int a}: 転がす円の半径 (a>0)
* {int dx}: x軸方向に平行移動する量
* {int dy}: y軸方向に平行移動する量 
* {double num}: 孤を何個生成するか
*/
void img_drawcycloid2(struct color c, int a, int dx, int dy, double num);

/*
* サイクロイドを描く関数 (中心は原点とする)
* {struct color c}: サイクロイドの色
* {int a}: 転がす円の半径 (a>0)
* {double num}: 孤を何個生成するか
*/
void img_drawcycloid(struct color c, int a, double num);

/*
* トロコイドの1点描く関数
* {struct color c}: トロコイドの色
* {int a}: 転がす円の半径 (a>0)
* {int b}: 円の中心から奇跡を描く点Pまでの距離 
* {double degree}: 角度 (*周期2πで孤を一つ作る)
*/
void img_drawtrochoidpoint(struct color c, int a, int b, double degree);

/*
* トロコイドを描く関数
* {struct color c}: トロコイドの色
* {int a}: 転がす円の半径 (a>0)
* {int b}: 円の中心から奇跡を描く点Pまでの距離
* {double num}: 孤を何個生成するか
*/
void img_drawtrochoid(struct color c, int a, int b, double num);

/*
* 円(縁)の1点を描く関数
* {struct color c}: 円の色
* {int r}: 円の半径 (r>0) 
* {int x}: 円の中心x座標 (x>0)
* {int y}: 円の中心y座標(y>0)
* {double degree}: 角度
*/
void img_drawcirclepoint(struct color c, int r, int x, int y, double degree);

/*
* 円の中心を指定して円の縁を描く関数
* {struct color c}: 円の色
* {int r}: 円の半径 (r>0) 
* {int x}: 円の中心x座標 (x>0)
* {int y}: 円の中心y座標(y>0)
*/
void img_drawcircle2(struct color c, int r, int x, int y);

/*
* 円(縁)を描く関数
* {struct color c}: 円の色
* {int r}: 円の半径 (r>0) 
*/
void img_drawcircle(struct color c, int r);

/*
* 中が埋まった円を描く関数 (img.h より移行)
* {struct color c}: 円の色
* {int x}: 円の中心x座標
* {int y}: 円の中心y座標
* {int r}: 円の半径
*/
void img_fillcircle(struct color c, double x, double y, double r);
