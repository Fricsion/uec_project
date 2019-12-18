#define WIDTH 300
#define HEIGHT 200
struct color
{
    unsigned char r, g, b;
};
void img_clear(void);
void img_write(void);
void img_putpixel(struct color c, int x, int y);