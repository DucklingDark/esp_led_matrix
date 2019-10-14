#include <Arduino.h>
#include "../lib/Matrix/Matrix.h"

Matrix *matrix;

void setup() {
    matrix = new Matrix();
}

void loop() {
    //matrix->drawZigZag();
    //matrix->drawMatrix();
    matrix->drawSuqare(1);
    delay(1000);
    matrix->drawSuqare(2);
    delay(1000);
    matrix->drawSuqare(3);
    delay(1000);
    matrix->drawSuqare(4);
    delay(1000);
    matrix->drawSuqare(5);
    delay(1000);
    matrix->drawSuqare(6);
    delay(1000);
    matrix->drawSuqare(7);
    delay(1000);
    matrix->drawSuqare(8);
    delay(1000);
}