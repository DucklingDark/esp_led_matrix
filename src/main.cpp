#include <Arduino.h>
#include "../lib/Matrix/Matrix.h"

Matrix *matrix;

void setup() {
    matrix = new Matrix();
}

void loop() {
    //matrix->drawZigZag();
    //matrix->drawMatrix();
    matrix->drawFilledSquare(1);
    delay(100);
    matrix->drawFilledSquare(2);
    delay(100);
    matrix->drawFilledSquare(3);
    delay(100);
    matrix->drawFilledSquare(4);
    delay(100);
    matrix->drawFilledSquare(5);
    delay(100);
    matrix->drawFilledSquare(6);
    delay(100);
    matrix->drawFilledSquare(7);
    delay(100);
    matrix->drawFilledSquare(8);
    delay(100);
    matrix->drawFilledSquare(7);
    delay(100);
    matrix->drawFilledSquare(6);
    delay(100);
    matrix->drawFilledSquare(5);
    delay(100);
    matrix->drawFilledSquare(4);
    delay(100);
    matrix->drawFilledSquare(3);
    delay(100);
    matrix->drawFilledSquare(2);
    delay(100);
    matrix->drawFilledSquare(0);
    delay(100);
}