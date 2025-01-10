#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

struct RGB {
    float r, g, b;
};

struct HSV {
    float h, s, v;
};

struct CMY {
    float c, m, y;
};

HSV rgbToHsv(RGB rgb) {
    HSV hsv;
    float minVal = min(min(rgb.r, rgb.g), rgb.b);
    float maxVal = max(max(rgb.r, rgb.g), rgb.b);
    float delta = maxVal - minVal;

    hsv.v = maxVal;

    if (maxVal != 0) {
        hsv.s = delta / maxVal;
    } else {
        hsv.s = 0;
        hsv.h = -1;
        return hsv;
    }

    if (rgb.r == maxVal) {
        hsv.h = (rgb.g - rgb.b) / delta;
    } else if (rgb.g == maxVal) {
        hsv.h = 2 + (rgb.b - rgb.r) / delta;
    } else {
        hsv.h = 4 + (rgb.r - rgb.g) / delta;
    }

    hsv.h *= 60;
    if (hsv.h < 0) {
        hsv.h += 360;
    }

    return hsv;
}

CMY rgbToCmy(RGB rgb) {
    CMY cmy;
    cmy.c = 1 - rgb.r;
    cmy.m = 1 - rgb.g;
    cmy.y = 1 - rgb.b;
    return cmy;
}

void displayRectangle(int x, int y, int width, int height, RGB rgb) {
    setfillstyle(SOLID_FILL, COLOR(rgb.r * 255, rgb.g * 255, rgb.b * 255));
    bar(x, y, x + width, y + height);
}

void menu() {
    cout << "Select a conversion:" << endl;
    cout << "1: RGB to HSV" << endl;
    cout << "2: RGB to CMY" << endl;
    cout << "3: Exit" << endl;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    RGB rgb;
    HSV hsv;
    CMY cmy;
    int choice;

    while (true) {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter RGB values (0-1 for each component): ";
                cin >> rgb.r >> rgb.g >> rgb.b;

                hsv = rgbToHsv(rgb);

                cleardevice();
                displayRectangle(100, 100, 200, 200, rgb);
                outtextxy(100, 310, "Original RGB");

                char hsvStr[100];
                sprintf(hsvStr, "HSV: H=%.2f S=%.2f V=%.2f", hsv.h, hsv.s * 100, hsv.v * 100);
                outtextxy(100, 340, hsvStr);
                break;

            case 2:
                cout << "Enter RGB values (0-1 for each component): ";
                cin >> rgb.r >> rgb.g >> rgb.b;

                cmy = rgbToCmy(rgb);

                cleardevice();
                displayRectangle(100, 100, 200, 200, rgb);
                outtextxy(100, 310, "Original RGB");

                char cmyStr[100];
                sprintf(cmyStr, "CMY: C=%.2f M=%.2f Y=%.2f", cmy.c * 100, cmy.m * 100, cmy.y * 100);
                outtextxy(100, 340, cmyStr);
                break;

            case 3:
                closegraph();
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }

        delay(2000); 
    }

    closegraph();
    return 0;
}
