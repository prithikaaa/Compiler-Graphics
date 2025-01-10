#include <iostream> 
#include <cmath>
#include <graphics.h>
#include <conio.h>
using namespace std;



void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        putpixel(x1, y1, WHITE); 
        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}


const int length = 200;     
const int originX = 320;    
const int originY = 100;    
const int radius = 20;     
void drawPendulum(int x, int y) {
    bresenhamLine(originX, originY, x, y);
    //bob
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(x, y, radius, radius); 
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int pendulumX = originX + length * sin(M_PI / 4); 
    int pendulumY = originY + length * cos(M_PI / 4);  

 
    drawPendulum(pendulumX, pendulumY);

    getch();  
    closegraph();  
    return 0;
}