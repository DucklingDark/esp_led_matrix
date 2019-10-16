#include <Arduino.h>
#include "../lib/Matrix/Matrix.h"

Matrix *matrix;

void setup() {
    matrix = new Matrix();
    matrix->setBrightness(5);
    Serial.begin(9600);
}

void loop() {
    //matrix->drawZigZag();
    //matrix->drawMatrix();

    /*for (int i = 1; i < 9; i++){
        matrix->clearMatrix();
        matrix->drawCenterSquare(i, false, CRGB(50, 0, 0));
        delay(100);
    }

    for (int i = 8; i > 0; i--){
        matrix->clearMatrix();
        matrix->drawCenterSquare(i, false, CRGB(50, 0, 0));
        delay(100);
    }*/

    /*matrix->clearMatrix(true);
    delay(500);
    matrix->setColor(CRGB(10, 50, 10));
    matrix->drawSquare(Point(2, 2), 3, true);
    delay(500);
    matrix->setColor(CRGB(50,10,90));
    matrix->drawSquare(Point(6, 10), 4);
    delay(500);
    matrix->setColor(CRGB(150,90,20));
    matrix->drawSquare(Point(14, 2));
    delay(500);
    matrix->setColor(CRGB(50, 10, 200));
    matrix->drawSquare(Point(13, 13), 5);
    delay(500);*/

    for (int i = -16; i < 17; i++){
        matrix->drawPackman(i);
        delay(250);
    }
}