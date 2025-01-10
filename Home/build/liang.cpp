#include <iostream>
#include <cmath>
#include <graphics.h>
#include <conio.h>
using namespace std;
bool liangBarsky(float x_min, float y_min, float x_max, float y_max, float &x1, float &y1, float &x2, float &y2) {
    float p1 = -(x2 - x1), p2 = -p1, p3 = -(y2 - y1), p4 = -p3;
    float q1 = x1 - x_min, q2 = x_max - x1, q3 = y1 - y_min, q4 = y_max - y1;

    float u1 = 0.0, u2 = 1.0;

   
    float p[4] = {p1, p2, p3, p4};
    float q[4] = {q1, q2, q3, q4};

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0) {
                return false;
            }
        } else {
            float u = q[i] / p[i];
            if (p[i] < 0) {
                u1 = max(u1, u);
            } else {
                u2 = min(u2, u); 
            }
        }
    }

    if (u1 > u2) {
        return false; 
    }
    x1 = x1 + u1 * (x2 - x1);
    y1 = y1 + u1 * (y2 - y1);
    x2 = x1 + u2 * (x2 - x1);
    y2 = y1 + u2 * (y2 - y1);

    return true;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    float x_min, y_min, x_max, y_max;
    cout << "Enter clipping window (x_min, y_min, x_max, y_max): ";
    cin >> x_min >> y_min >> x_max >> y_max;

   
    float x1, y1, x2, y2;
    cout << "Enter the coordinates of the line (x1, y1, x2, y2): ";
    cin >> x1 >> y1 >> x2 >> y2;


    setcolor(WHITE);
    rectangle(x_min, y_min, x_max, y_max);

 
    if (liangBarsky(x_min, y_min, x_max, y_max, x1, y1, x2, y2)) {
     
        setcolor(RED);
        line(x1, y1, x2, y2);
        cout << "Line clipped successfully.\n";
    } else {
        cout << "Line lies completely outside the clipping window.\n";
    }

    getch();
    closegraph();
    return 0;
}