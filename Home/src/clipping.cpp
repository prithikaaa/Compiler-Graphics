#include <iostream>
#include <cmath>
#include <graphics.h>
#include <conio.h>
using namespace std;
const int INSIDE = 0;
const int LEFT = 1;  
const int RIGHT = 2; 
const int BOTTOM = 4;
const int TOP = 8;    
int x_min, y_min, x_max, y_max;

int computeCode(int x, int y) {
    int code = INSIDE;
    if (x < x_min)      
        code |= LEFT;
    else if (x > x_max)
        code |= RIGHT;
    if (y < y_min)      
        code |= BOTTOM;
    else if (y > y_max)  
        code |= TOP;
    return code;
}

void cohenSutherlandClip(int &x1, int &y1, int &x2, int &y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
     
            accept = true;
            break;
        } else if (code1 & code2) {
          
            break;
        } else {
            int code_out;
            int x, y;

            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            if (code_out & TOP) {          
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (code_out & RIGHT) { 
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (code_out & LEFT) {  
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
}

void windowToViewport(int x_w1, int y_w1, int x_w2, int y_w2, int x_v1, int y_v1, int x_v2, int y_v2) {

    float sx = float(x_v2 - x_v1) / (x_w2 - x_w1);
    float sy = float(y_v2 - y_v1) / (y_w2 - y_w1);

    rectangle(x_v1, y_v1, x_v2, y_v2);

    int x1, y1, x2, y2;
    cout << "Enter the coordinates of the line (x1, y1, x2, y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    cohenSutherlandClip(x1, y1, x2, y2);

    int x1_v = x_v1 + (x1 - x_w1) * sx;
    int y1_v = y_v1 + (y1 - y_w1) * sy;
    int x2_v = x_v1 + (x2 - x_w1) * sx;
    int y2_v = y_v1 + (y2 - y_w1) * sy;

    setcolor(GREEN);
    line(x1_v, y1_v, x2_v, y2_v);
}

int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    cout << "Enter clipping window (x_min, y_min, x_max, y_max): ";
    cin >> x_min >> y_min >> x_max >> y_max;
    cout << "Enter viewport (x_v1, y_v1, x_v2, y_v2): ";
    int x_v1, y_v1, x_v2, y_v2;
    cin >> x_v1 >> y_v1 >> x_v2 >> y_v2;

    setcolor(WHITE);
    rectangle(x_min, y_min, x_max, y_max);

    windowToViewport(x_min, y_min, x_max, y_max, x_v1, y_v1, x_v2, y_v2);

    getch();
    closegraph();
    return 0;
}