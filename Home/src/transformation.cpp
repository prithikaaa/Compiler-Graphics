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

void drawRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    bresenhamLine(x1, y1, x2, y2);
    bresenhamLine(x2, y2, x3, y3);
    bresenhamLine(x3, y3, x4, y4);
    bresenhamLine(x4, y4, x1, y1);
}

void transformRectangle(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int &x4, int &y4, 
                        char transform, float param1 = 0, float param2 = 0) {
    switch (transform) {
        case 't': 
            x1 += param1; y1 += param2;
            x2 += param1; y2 += param2;
            x3 += param1; y3 += param2;
            x4 += param1; y4 += param2;
            break;

        case 'r':
        {
            float theta = param1 * M_PI / 180.0;
            int newX1 = x1 * cos(theta) - y1 * sin(theta);
            int newY1 = x1 * sin(theta) + y1 * cos(theta);
            int newX2 = x2 * cos(theta) - y2 * sin(theta);
            int newY2 = x2 * sin(theta) + y2 * cos(theta);
            int newX3 = x3 * cos(theta) - y3 * sin(theta);
            int newY3 = x3 * sin(theta) + y3 * cos(theta);
            int newX4 = x4 * cos(theta) - y4 * sin(theta);
            int newY4 = x4 * sin(theta) + y4 * cos(theta);
            
            x1 = newX1; y1 = newY1;
            x2 = newX2; y2 = newY2;
            x3 = newX3; y3 = newY3;
            x4 = newX4; y4 = newY4;
        }
            break;

        case 's': 
            x1 *= param1; y1 *= param2;
            x2 *= param1; y2 *= param2;
            x3 *= param1; y3 *= param2;
            x4 *= param1; y4 *= param2;
            break;

        case 'x': 
            y1 = -y1; y2 = -y2;
            y3 = -y3; y4 = -y4;
            break;

        case 'y':
            x1 = -x1; x2 = -x2;
            x3 = -x3; x4 = -x4;
            break;

        case 'h': 
            x1 = x1 + param1 * y1;
            x2 = x2 + param1 * y2;
            x3 = x3 + param1 * y3;
            x4 = x4 + param1 * y4;
            break;

        default:
            break;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 200, y3 = 200;
    int x4 = 100, y4 = 200;

    drawRectangle(x1, y1, x2, y2, x3, y3, x4, y4);
    getch();

    transformRectangle(x1, y1, x2, y2, x3, y3, x4, y4, 't', 50, 50);
    drawRectangle(x1, y1, x2, y2, x3, y3, x4, y4);
    getch();
    transformRectangle(x1, y1, x2, y2, x3, y3, x4, y4, 'r', 45);
    drawRectangle(x1, y1, x2, y2, x3, y3, x4, y4);
    getch();

    transformRectangle(x1, y1, x2, y2, x3, y3, x4, y4, 's', 2, 2);
    drawRectangle(x1, y1, x2, y2, x3, y3, x4, y4);
    getch();

    // Reflection across x-axis
    transformRectangle(x1, y1, x2, y2, x3, y3, x4, y4, 'x');
    drawRectangle(x1, y1, x2, y2, x3, y3, x4, y4);
    getch();

    // Shearing (with factor 1.5 along x-axis)
    transformRectangle(x1, y1, x2, y2, x3, y3, x4, y4, 'h', 1.5);
    drawRectangle(x1, y1, x2, y2, x3, y3, x4, y4);
    getch();

    closegraph();
    return 0;
}