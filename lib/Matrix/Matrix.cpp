#include "Matrix.h"

Matrix::Matrix(){
    FastLED.addLeds<WS2812B, MATRIX_PIN, COLOR_ORDER> (leds_, NUM_LEDS); 
    setBrightness(BRIGHTNESS);
    clearMatrix();

    if (CURRENT_LIMIT > 0){
        //FastLED.setMaxPowerInVoltsAndMilliamps(5, CURRENT_LIMIT);
    }

    for (int i = 0; i < NUM_LEDS; i++){
        leds_[i] = CRGB(red_, green_, blue_);
        red_ += 1;
        wait_(10);
    }

    red_ = 0;
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
            ledNumber = getPixelNum_(i, j);
            leds_[ledNumber] = getRandomRGB_();
            wait_(10);
        }
    }
}

void Matrix::fillAll(){
    clearMatrix();
}

void Matrix::setPixelXY(uint8_t x, uint8_t y, CRGB color){
    leds_[getPixelNum_(x, y)] = color;
    wait_(1);
}

void Matrix::setPixelXY(uint8_t x, uint8_t y, CHSV color){

}

void Matrix::drawFilledSquare(uint8_t size){
    clearMatrix();
    
    if (size > 0 && size <= 8){
        uint8_t newSize = size * 2;

        for (int i = 0; i < newSize; i++){
            for (int j = 0; j < newSize; j++){
                leds_[getPixelNum_(CENTER_X - size + 1 + i, CENTER_Y - size + 1 + j)] = CRGB(100, 5, 100);
                //wait_(1);
            }
        }

        FastLED.show();
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

uint8_t Matrix::getPixelNum_(uint8_t x, uint8_t y){
    if ((y % 2 == 0) || MATRIX_TYPE){
        return (y * MATRIX_WIDTH + x);
    } else {
        return (y * MATRIX_WIDTH + MATRIX_WIDTH - x - 1);
    }
}

void Matrix::wait_(uint32_t time){
    FastLED.delay(time);
}
