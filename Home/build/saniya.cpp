#include <graphics.h>
#include <conio.h>
#include <dos.h>

// Function to draw a car
void drawCar(int x, int y) {
    // Body of the car
    rectangle(x, y, x + 100, y + 40);
    rectangle(x + 20, y - 20, x + 80, y);

    // Wheels of the car
    circle(x + 25, y + 40, 10);
    circle(x + 75, y + 40, 10);

    // Filling colors
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(x + 50, y + 10, WHITE);

    setfillstyle(SOLID_FILL, RED);
    floodfill(x + 50, y - 10, WHITE);

    setfillstyle(SOLID_FILL, BLACK);
    floodfill(x + 25, y + 40, WHITE);
    floodfill(x + 75, y + 40, WHITE);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x = 0, y = 300;  // Starting position of the car

    // Animation loop
    while (x < getmaxx() - 100) {
        cleardevice();      // Clear the screen
        drawCar(x, y);      // Draw the car at the new position
        delay(10);          // Delay to create animation effect
        x += 5;             // Move the car to the right
    }

    getch();
    closegraph();
    return 0;
}