#include "Matrix.h"

Matrix::Matrix(){
    FastLED.addLeds<WS2812B, MATRIX_PIN, COLOR_ORDER> (leds_, NUM_LEDS); 
    setBrightness(BRIGHTNESS);
    clearMatrix();

    if (CURRENT_LIMIT > 0){
        //FastLED.setMaxPowerInVoltsAndMilliamps(5, CURRENT_LIMIT);
    }
}

void Matrix::drawZigZag(){
    clearMatrix();
    
    for (int i = 0; i < NUM_LEDS; i++){
        leds_[i] = getRandomRGB_();
        wait_(10);
    }
}

void Matrix::drawMatrix(){
    uint8_t ledNumber = 0;
    clearMatrix();

    for (int i = 0; i < MATRIX_WIDTH; i++){
        for (int j = 0; j< MATRIX_HEIGHT; j++){
            ledNumber = getPixelNum_(Point(i, j));
            leds_[ledNumber] = getRandomRGB_();
            wait_(10);
        }
    }
}

void Matrix::fillAll(){
    clearMatrix();
}

void Matrix::setPixelXY(Point point, CRGB color){
    leds_[getPixelNum_(point)] = color;
    wait_(1);
}

void Matrix::setPixelXY(Point point, CHSV color){

}

void Matrix::drawCenterSquare(uint8_t size, bool filled, CRGB color){    
    if (size > 0 && size <= 8){
        uint8_t newSize = size * 2;

        for (int i = 0; i < newSize; i++){
            for (int j = 0; j < newSize; j++){
                leds_[getPixelNum_(Point(CENTER_X - size + 1 + j, CENTER_Y - size + 1 + i))] = color;
            }
        }

        if (filled == false){
            drawCenterSquare(size - 1, filled = true);
        }

        show_();
    }
}

void Matrix::clearMatrix(){
    FastLED.clear();
}

void Matrix::setBrightness(uint8_t brightness){
    FastLED.setBrightness(brightness);
}
/*!
 * PRIVATE FUNCTIONS
 */
CRGB Matrix::getRandomRGB_(){
    return CRGB(random(0, 150), random(0, 150), random(0, 150));
}

CHSV Matrix::getRandomHSV_(){
    return CHSV(random(50, 255), random(50, 255), random(50, 255));
}

uint8_t Matrix::getPixelNum_(Point point){
    if ((point.y % 2 == 0) || MATRIX_TYPE){
        return (point.y * MATRIX_WIDTH + point.x);
    } else {
        return (point.y * MATRIX_WIDTH + MATRIX_WIDTH - point.x - 1);
    }
}

void Matrix::wait_(uint32_t time){
    FastLED.delay(time);
}
void Matrix::show_(){
    FastLED.show();
}