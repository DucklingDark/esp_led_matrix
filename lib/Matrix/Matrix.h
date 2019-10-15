#pragma once
#include <Arduino.h>
#include "../FastLED/FastLED.h"

#define NUM_LEDS        256
#define MATRIX_TYPE     0
#define BRIGHTNESS      10   
#define CURRENT_LIMIT   500
#define COLOR_ORDER     GRB
#define MATRIX_PIN      2
#define MATRIX_WIDTH    16
#define MATRIX_HEIGHT   16
#define CENTER_X        7
#define CENTER_Y        7

struct Point{
    uint8_t x;
    uint8_t y;

    Point(uint8_t x_, uint8_t y_){
        x = x_;
        y = y_;
    }
};

class Matrix{
    public :
        Matrix();
        void drawZigZag();
        void drawMatrix();
        void fillAll();
        void setPixelXY(Point point, CRGB color);
        void setPixelXY(Point point, CHSV color);
        void drawCenterSquare(uint8_t size, bool filled = false, CRGB color = CRGB(0,0,0));
        void clearMatrix();
        void setBrightness(uint8_t brightness);
    private:
        CRGB getRandomRGB_();
        CHSV getRandomHSV_();
        uint8_t getPixelNum_(Point point);
        void wait_(uint32_t time);
        void show_();

        CRGBArray<NUM_LEDS> leds_;
        uint8_t  hue_           = 255;
        uint8_t  saturation_    = 255;
        uint8_t  value_         = 255;
        uint8_t  red_           = 0;
        uint8_t  green_         = 0;
        uint8_t  blue_          = 0;
};