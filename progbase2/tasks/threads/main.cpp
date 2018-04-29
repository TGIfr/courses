
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <thread>
#include <mutex>

#include <progbase.h>
#include <progbase-cpp/console.h>
#include "include/graphics.h"


using namespace std;
using namespace progbase::console;

mutex m;

 void clearRect(Vec2D location, Vec2D size) {
     Console::setCursorAttribute(CursorAttributes::BG_DEFAULT);
 	for (int y = 0; y < size.y; y++) {
 		for (int x = 0; x < size.x; x++) {
 			Vec2D pos = { location.x + x, location.y + y };
 			Graphics_drawPixel(NULL, pos, CursorAttributes::BG_BLACK);
 		}
 	}
 }



void printSquare(
        Vec2D start,
        double length,
        CursorAttributes color
){
    Vec2D topRight{
            .x = start.x + length,
            .y = start.y
    };
    Vec2D downLeft{
            .x = start.x,
            .y = start.y - length
    };
    Vec2D downRight{
            .x = start.x + length,
            .y = start.y - length
    };

    Graphics_drawLine(NULL, start, topRight, color);
    Graphics_drawLine(NULL, downRight, topRight, color);
    Graphics_drawLine(NULL, start, downLeft, color);
    Graphics_drawLine(NULL, downLeft, downRight, color);
}

void printTriangle(
        Vec2D pointA,
        Vec2D pointB,
        Vec2D pointC,

        CursorAttributes color
){

    Graphics_drawLine(NULL, pointA, pointB, color);
    Graphics_drawLine(NULL, pointB, pointC, color);
    Graphics_drawLine(NULL, pointC, pointA, color);

}
void threadSquare(double &length, CursorAttributes &color, double &distance, double &period){
    Vec2D consoleCenter = (Vec2D){20, 12};
    long timeStart = time(0);
    long timeNow;
    float degrees = 0;
    while (1) {
        timeNow = time(0);

        if (timeNow - timeStart > period / 1000) {

            timeStart = time(0);
            double radians = degrees * M_PI / 180.0;

            Vec2D rotateVector = (Vec2D){1, 1};
            rotateVector = Vec2D_normalize(rotateVector);
            rotateVector = Vec2D_multByNumber(rotateVector, distance);
            rotateVector = Vec2D_rotate(rotateVector, radians);
            Vec2D center = Vec2D_add(consoleCenter, rotateVector);

            double fromCenterDist = length * sqrt(2) / 2;
            Vec2D toStartVector = (Vec2D){-1, 1};
            toStartVector = Vec2D_normalize(toStartVector);
            toStartVector = Vec2D_multByNumber(toStartVector, fromCenterDist);
            Vec2D start = Vec2D_add(center, toStartVector);

            m.lock();
            clearRect((Vec2D){0, 0},(Vec2D){40, 24} );

            printSquare(
                    start,
                    length,
                    color
            );
            //printf("%.1f   %.1f", center.x, center.y);
            m.unlock();
            degrees += 100;
        }
    }
}
void threadTriangle(double &length, CursorAttributes &color, double &period){
    Vec2D consoleCenter = (Vec2D){60, 12};
    long timeStart = time(0);
    long timeNow;
    float degrees = 0;
    while (1) {
        timeNow = time(0);

        if (timeNow - timeStart > period  / 1000) {
            timeStart = time(0);
            double radians = degrees * M_PI / 180.0;

            Vec2D rotateVectorA = (Vec2D){1, 1};
            rotateVectorA = Vec2D_normalize(rotateVectorA);
            rotateVectorA = Vec2D_multByNumber(rotateVectorA, length / sqrt(3));
            rotateVectorA = Vec2D_rotate(rotateVectorA, radians);
            Vec2D rotateVectorB = Vec2D_rotate(rotateVectorA, 60 * M_PI / 180);
            Vec2D rotateVectorC = Vec2D_rotate(rotateVectorA, 120 * M_PI / 180);
            Vec2D pointA = Vec2D_add(consoleCenter, rotateVectorA);
            Vec2D pointB = Vec2D_add(consoleCenter, rotateVectorB);
            Vec2D pointC = Vec2D_add(consoleCenter, rotateVectorC);


            m.lock();
            clearRect((Vec2D){40, 0},(Vec2D){80, 24} );
            printTriangle(
                    pointA,
                    pointB,
                    pointC,
                    color
            );

            m.unlock();
            degrees +=10;
        }
    }
}


int main(void) {
    Console::setSize(24, 80);
    Console::clear();
    double length = 10;
    CursorAttributes color = CursorAttributes::BG_BLUE;
    CursorAttributes color2 = CursorAttributes::BG_RED;
    double distance = 2;
    double period = 1;
    thread square(threadSquare, ref(length), ref(color), ref(distance), ref(period) );
    thread triangle( threadTriangle, ref(length), ref(color2), ref(period));

    while(!Console::isKeyDown()){

    }
    Console::reset();
    square.detach();
    triangle.detach();
    return 0;
}