#include <Arduino.h>
#include "../lib/Matrix/Matrix.h"

Matrix *matrix;

void setup() {
    matrix = new Matrix();
    matrix->setBrightness(50);
}

void loop() {
    //matrix->drawZigZag();
    //matrix->drawMatrix();

    for (int i = 1; i < 9; i++){
        matrix->clearMatrix();
        matrix->drawCenterSquare(i, false, CRGB(50, 0, 0));
        delay(100);
    }

    for (int i = 8; i > 0; i--){
        matrix->clearMatrix();
        matrix->drawCenterSquare(i, false, CRGB(50, 0, 0));
        delay(100);
    }
}