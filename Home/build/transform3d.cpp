#include <graphics.h>
#include <math.h>
#include <iostream>

using namespace std;

struct Point3D {
    float x, y, z;
};

const float d = 500; 
const int centerX = 400; 
const int centerY = 200; 

void project(Point3D p3d, int &x2d, int &y2d) {
    x2d = centerX + (int)((d * p3d.x) / (d + p3d.z));
    y2d = centerY - (int)((d * p3d.y) / (d + p3d.z));
}

void labelVertices(int x[], int y[]) {
    char labels[8] = {'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'Z'};
    for (int i = 0; i < 8; i++) {
        char label[2] = {labels[i], '\0'};  
        setcolor(WHITE);
        outtextxy(x[i], y[i], label); 
    }
}

void drawCube(Point3D cube[8]) {
    int x[8], y[8];

    for (int i = 0; i < 8; i++) {
        project(cube[i], x[i], y[i]);
    }

    labelVertices(x, y);

    setcolor(WHITE); 
    for (int i = 0; i < 4; i++) {
        line(x[i], y[i], x[(i + 1) % 4], y[(i + 1) % 4]);  
    }

    setcolor(WHITE); 
    for (int i = 4; i < 8; i++) {
        line(x[i], y[i], x[(i - 3) % 4 + 4], y[(i - 3) % 4 + 4]);  
    }

    setcolor(WHITE); 
    for (int i = 0; i < 4; i++) {
        line(x[i], y[i], x[i + 4], y[i + 4]);  
    }
}

Point3D rotateY(Point3D p, float angle) {
    Point3D result;
    float rad = angle * M_PI / 180.0; 
    result.x = p.x * cos(rad) - p.z * sin(rad);
    result.y = p.y;
    result.z = p.x * sin(rad) + p.z * cos(rad);
    return result;
}

Point3D scale(Point3D p, float sx, float sy, float sz) {
    Point3D result;
    result.x = p.x * sx;
    result.y = p.y * sy;
    result.z = p.z * sz;
    return result;
}

Point3D translate(Point3D p, float tx, float ty, float tz) {
    Point3D result;
    result.x = p.x + tx;
    result.y = p.y + ty;
    result.z = p.z + tz;
    return result;
}

void menu() {
    cout << "Select an option:" << endl;
    cout << "1: Translate" << endl;
    cout << "2: Rotate" << endl;
    cout << "3: Scale" << endl;
    cout << "4: Exit" << endl;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    Point3D cube[8] = {
        {-20, -20, -20}, {20, -20, -20}, {20, 20, -20}, {-20, 20, -20},
        {-20, -20, 20}, {20, -20, 20}, {20, 20, 20}, {-20, 20, 20}
    };

    float angle = 0.0;
    char ch;
    int choice;
    float tx = 0, ty = 0, tz = 0, sx = 1.0, sy = 1.0, sz = 1.0;

    while (true) {
        cleardevice(); 

        Point3D transformedCube[8];
        for (int i = 0; i < 8; i++) {
            transformedCube[i] = translate(cube[i], tx, ty, tz); 
            transformedCube[i] = rotateY(transformedCube[i], angle);
            transformedCube[i] = scale(transformedCube[i], sx, sy, sz);
        }

        drawCube(transformedCube);

        delay(100); 
        menu();
        cin >> choice;
        
        switch (choice) {
            case 1: 
                cout << "Enter translation along x, y, z: ";
                cin >> tx >> ty >> tz;
                break;
            case 2:
                cout << "Enter rotation angle: ";
                cin >> angle;
                break;
            case 3: 
                cout << "Enter scaling factors (sx, sy, sz): ";
                cin >> sx >> sy >> sz;
                break;
            case 4: 
                closegraph();
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    closegraph();
    return 0;
}