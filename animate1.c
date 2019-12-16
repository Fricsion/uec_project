// heartbeat --- two circles going large and small
#include "img.h"
#include <math.h>
#define PI 3.14159265358979

int main(void) {
  struct color c1 = { 30, 255, 0 };
  struct color c2 = { 255, 0, 0 };
  int i;
  for(i = 0; i < 30; ++i) {
    double sx = sin(2*PI*i/15), cx = cos(2*PI*i/15);
    double rad = 30 - 20*sx;
    img_clear();
    img_fillcircle(c2, 150-rad/2, 100, rad);
    img_fillcircle(c2, 150+rad/2, 100, rad);
    img_write();
  }
  for(i = 0; i < 10; ++i) {
    double sx = sin(2*PI*i/5), cx = cos(2*PI*i/5);
    double rad = 30 - 20*sx;
    img_clear();
    img_fillcircle(c2, 150-rad/2, 100, rad);
    img_fillcircle(c2, 150+rad/2, 100, rad);
    img_write();
  }
}
