#define _USE_MATH_DEFINES
#include "img.h"

/*
* 円(縁)の1点を描く関数
* {struct color c}: 円の色
* {int r}: 円の半径 (r>0) 
* {int x}: 円の中心x座標 (x>0)
* {int y}: 円の中心y座標(y>0)
* {double degree}: 角度
*/
void img_drawCirclePoint(struct color c, int x, int y, int r, double degree);

/*
* 円(縁)を描く関数
* {struct color c}: 円の色
* {int r}: 円の半径 (r>0) 
*/
void img_drawCircle(struct color c, int r);

/*
* 円の中心を指定して円の縁を描く関数
* {struct color c}: 円の色
* {int r}: 円の半径 (r>0) 
* {int x}: 円の中心x座標 (x>0)
* {int y}: 円の中心y座標(y>0)
*/
void img_drawCircle2(struct color c, int x, int y, int r);

/*
* 中が埋まった円を描く関数 (img.h より移行)
* {struct color c}: 円の色
* {int x}: 円の中心x座標
* {int y}: 円の中心y座標
* {int r}: 円の半径
*/
void img_fillCircle(struct color c, double x, double y, double r);

/*
* 長方形を描く関数
* {struct color c}: 長方形の色
* {int x1}: 長方形の左上端のx座標
* {int y1}: 長方形の左上端のy座標
* {int width}: 長方形の横
* {int height}: 長方形の高さ
*/
void img_fillRectangle(struct color c, int x1, int y1, int width, int height);

/*
* 直線を描く関数
* {struct color c}: 線の色
* {double a}: 傾き
* {int b}: y切片
* {int x1}: 直線の始点のx座標
* {int x2}: 直線の終点のx座標
*/
void img_drawLine(struct color c, double a, int b, int x1, int x2);

/*
* サイクロイドの1点描く関数
* {struct color c}: サイクロイドの色
* {int a}: 転がす円の半径 (a>0)
* {int dx}: x軸方向に平行移動する量
* {int dy}: y軸方向に平行移動する量 
* {double degree}: 角度 (*周期2πで孤を一つ作る)
*/
void img_drawCycloidPoint(struct color c, int a, int dx, int dy, double degree);

/*
* サイクロイドの1点描く関数
* {struct color c}: サイクロイドの色
* {int a}: 転がす円の半径 (a>0)
* {int dx}: x軸方向に平行移動する量
* {int dy}: y軸方向に平行移動する量 
* {double degree}: 角度 (*周期2πで孤を一つ作る)
* {int bold}: 点の太さ
*/
void img_drawCycloidPoint2(struct color c, int a, int dx, int dy, double degree, int bold);

// 逆向きサイクロイド用
void img_drawCycloidPointRev(struct color c, int a, int dx, int dy, double degree);

void img_drawCycloidPointRev2(struct color c, int a, int dx, int dy, double degree, int bold);

void img_drawCycloidRev(struct color c, int a, int dx, int dy, double degree);

// 逆向きトロコイド用

void img_drawTrochoidPointRev(struct color c, int dx, int dy, int a, int b, double degree);
void img_drawTrochoidPointRev2(struct color c, int dx, int dy, int a, int b, double degree, int bold);
void img_drawTrochoidRev(struct color c, int x, int y, int a, int b, double degree);

/*
* サイクロイドを描く関数 (中心は原点とする)
* {struct color c}: サイクロイドの色
* {int a}: 転がす円の半径 (a>0)
* {double num}: 孤を何個生成するか
*/
void img_drawCycloid(struct color c, int a, double num);

/*
* サイクロイドを描く関数 (平行移動ver)
* {struct color c}: サイクロイドの色
* {int a}: 転がす円の半径 (a>0)
* {int dx}: x軸方向に平行移動する量
* {int dy}: y軸方向に平行移動する量 
* {double num}: 孤を何個生成するか
*/
void img_drawCycloid2(struct color c, int a, int dx, int dy, double num);

/*
* サイクロイドを描く関数 (平行移動ver)
* {struct color c}: サイクロイドの色
* {int a}: 転がす円の半径 (a>0)
* {int dx}: x軸方向に平行移動する量
* {int dy}: y軸方向に平行移動する量 
* {double degree}: どこまでサイクロイドを生成するか(角度)
*/
void img_drawCycloid3(struct color c, int a, int dx, int dy, double degree);

/*
* トロコイドの1点描く関数
* {struct color c}: トロコイドの色
* {int a}: 転がす円の半径 (a>0)
* {int b}: 円の中心から奇跡を描く点Pまでの距離 
* {double degree}: 角度 (*周期2πで孤を一つ作る)
*/

void img_drawTrochoidPoint(struct color c, int a, int b, double degree);

/*
* トロコイドの1点描く関数 (平行移動ver)
* {struct color c}: トロコイドの色
* {int dx}: x軸方向へ平行移動する量
* {int dy}: y軸方向へ平行移動する量
* {int a}: 転がす円の半径 (a>0)
* {int b}: 円の中心から奇跡を描く点Pまでの距離 
* {double degree}: 角度 (*周期2πで孤を一つ作る)
*/
void img_drawTrochoidPoint2(struct color c, int dx, int dy, int a, int b, double degree, int bold);

/*
* トロコイドを描く関数
* {struct color c}: トロコイドの色
* {int a}: 転がす円の半径 (a>0)
* {int b}: 円の中心から奇跡を描く点Pまでの距離
* {double num}: 孤を何個生成するか
*/
void img_drawTrochoid(struct color c, int a, int b, double num);

/*
* トロコイドを描く関数
* {struct color c}: トロコイドの色
* {int a}: 転がす円の半径 (a>0)
* {int b}: 円の中心から奇跡を描く点Pまでの距離
* {double degree}: どこまでサイクロイドを生成するか(角度)
*/
void img_drawTrochoid2(struct color c, int x, int y, int a, int b, double degree);

//3.14定義
double PI();
double PI_2();
double PI_4();
