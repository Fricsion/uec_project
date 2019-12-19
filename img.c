#include <stdio.h>
#include <stdlib.h>
#include "img.h"

static unsigned char buf[HEIGHT][WIDTH][3];
static int filecnt = 0;
static char fname[100];

struct color bgColor = {180, 140, 80};

void img_clear(void)
{
  int i, j;
  for (j = 0; j < HEIGHT; ++j)
  {
	  for (i = 0; i < WIDTH; ++i)
	  {
		  buf[j][i][0] = bgColor.r;
		  buf[j][i][1] = bgColor.g;
		  buf[j][i][2] = bgColor.b;
	  }
  }
}

void img_write(void)
{
  sprintf(fname, "outputs/img%04d.ppm", ++filecnt);
  FILE *f = fopen(fname, "wb");
  if (f == NULL)
  {
    fprintf(stderr, "can't open %s\n", fname);
    exit(1);
  }
  fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
  fwrite(buf, sizeof(buf), 1, f);
  fclose(f);
}

void img_putpixel(struct color c, int x, int y)
{
  if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
  {
    return;
  }
  buf[HEIGHT - y - 1][x][0] = c.r;
  buf[HEIGHT - y - 1][x][1] = c.g;
  buf[HEIGHT - y - 1][x][2] = c.b;
}
