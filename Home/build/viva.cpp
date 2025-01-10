#include <graphics.h>
#include <math.h>
#include <conio.h>
using namespace std;
void bresenhamCircle(int xc, int yc, int r, int color) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    setcolor(color);
    while (x <= y) {
        putpixel(xc + x, yc + y, color);
        putpixel(xc - x, yc + y, color);
        putpixel(xc + x, yc - y, color);
        putpixel(xc - x, yc - y, color);
        putpixel(xc + y, yc + x, color);
        putpixel(xc - y, yc + x, color);
        putpixel(xc + y, yc - x, color);
        putpixel(xc - y, yc - x, color);
        x++;
        if (d < 0) {
            d += 4 * x + 6;
        } else {
            y--;
            d += 4 * (x - y) + 10;
        }
    }
}
void bresenhamEllipse(int xc, int yc, int rx, int ry, int color) {
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;
    setcolor(color);
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;
    while (dx < dy) {
        putpixel(xc + x, yc + y, color);
        putpixel(xc - x, yc + y, color);
        putpixel(xc + x, yc - y, color);
        putpixel(xc - x, yc - y, color);

        if (d1 < 0) {
            x++;
            dx += 2 * ry * ry;
            d1 += dx + (ry * ry);
        } else {
            x++;
            y--;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d1 += dx - dy + (ry * ry);
        }
    }
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
    while (y >= 0) {
        putpixel(xc + x, yc + y, color);
        putpixel(xc - x, yc + y, color);
        putpixel(xc + x, yc - y, color);
        putpixel(xc - x, yc - y, color);
        if (d2 > 0) {
            y--;
            dy -= 2 * rx * rx;
            d2 += (rx * rx) - dy;
        } else {
            y--;
            x++;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d2 += dx - dy + (rx * rx);
        }
    }
}
void drawPlanet(int xc, int yc, int r, int color) {
    bresenhamCircle(xc, yc, r, color);
    setfillstyle(SOLID_FILL, color);
    floodfill(xc, yc, color);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int sunX = 320, sunY = 240, sunR = 50;
    int orbitColors[] = {LIGHTCYAN, BLUE, RED};
    int planetColors[] = {LIGHTMAGENTA, WHITE, LIGHTGREEN};
    int orbitRx[] = {100, 150, 200};
    int orbitRy[] = {60, 90, 120};
    int planetRadius[] = {10, 15, 20};
    float angles[] = {0, 0, 0};
    drawPlanet(sunX, sunY, sunR, YELLOW);
    for (int i = 0; i < 3; i++) {
            bresenhamEllipse(sunX, sunY, orbitRx[i], orbitRy[i], orbitColors[i]);
        }
    for (int i = 0; i < 3; i++) {
            int px = sunX + orbitRx[i] * cos(angles[i]);
            int py = sunY + orbitRy[i] * sin(angles[i]);
            drawPlanet(px, py, planetRadius[i], planetColors[i]);
    }
    getch();
    closegraph();
    return 0;
}
