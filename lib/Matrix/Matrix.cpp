#include "Matrix.h"

Matrix::Matrix(){
    FastLED.addLeds<WS2812B, MATRIX_PIN, COLOR_ORDER> (leds_, NUM_LEDS); 
    setBrightness(BRIGHTNESS);
    clearMatrix();

    if (CURRENT_LIMIT > 0){
        //FastLED.setMaxPowerInVoltsAndMilliamps(5, CURRENT_LIMIT);
    }

    setColor(CRGB(0, 0, 0));
}

void Matrix::drawZigZag(){    
    for (int i = 0; i < NUM_LEDS; i++){
        leds_[i] = getRandomRGB_();
        wait_(10);
    }
}

void Matrix::drawMatrix(){
    uint8_t ledNumber = 0;

    for (int i = 0; i < MATRIX_WIDTH; i++){
        for (int j = 0; j< MATRIX_HEIGHT; j++){
            ledNumber = getPixelNum_(Point(i, j));
            leds_[ledNumber] = getRandomRGB_();
            wait_(10);
        }
    }
}

void Matrix::fillAll(CRGB color){
    for (int i = 0; i < NUM_LEDS; i++){
        leds_[i] = color;
    }
}

void Matrix::setPixelXY(Point point, CRGB color){
    leds_[getPixelNum_(Point(point.y, point.x))] = color;
    wait_(1);
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

void Matrix::drawSquare(Point startPoint, uint8_t size, bool filled){
    if (startPoint.x >= 0 && startPoint.x <= 14){
        if (startPoint.y >= 0 && startPoint.y <= 14){
            if (size >= 1 && size <= 16){
                if (filled){
                    Point endPoint;
                    endPoint.x = startPoint.x + size - 1;
                    endPoint.y = startPoint.y + size - 1;
                    drawByCoordinates_(startPoint, endPoint);                    
                } else {
                    drawByCoordinates_(startPoint, 
                                Point(startPoint.x, startPoint.y + size - 1));

                    drawByCoordinates_(startPoint, 
                                Point(startPoint.x + size - 1, startPoint.y));

                    drawByCoordinates_(Point(startPoint.x + size -1, startPoint.y), 
                                Point(startPoint.x  + size - 1, startPoint.y + size - 1));

                    drawByCoordinates_(Point(startPoint.x, startPoint.y + size -1), 
                                Point(startPoint.x  + size - 1, startPoint.y + size - 1));
                }

                show_();
            }
        }
    }
}

void Matrix::clearMatrix(bool show){
    FastLED.clear();

    if (show){
        show_();
    }
}

void Matrix::setBrightness(uint8_t brightness){
    FastLED.setBrightness(brightness);
}

void Matrix::setColor(CRGB color){
    color_ = color;
}

void Matrix::drawPackman(uint8_t x){
    uint8_t pixelCount = 0;
    bool setPixel = false;
    clearMatrix();
    setColor(CRGB(150, 100, 0));

    for (int i = 0; i < MATRIX_WIDTH; i++){
        for (int j = 0 + x; j < MATRIX_HEIGHT + x; j++){
            switch(imageStage_){
                case 0:
                    if (pacman1[pixelCount] == 1){
                        setPixel = true;
                    }
                    break;
                case 1:
                    if (pacman2[pixelCount] == 1){
                        setPixel = true;
                    }
                    break;
                case 2:
                    if (pacman3[pixelCount] == 1){
                        setPixel = true;
                    }
                    break;
            }

            if (setPixel){
                leds_[getPixelNum_(Point(i,j))] = color_;
            }

            setPixel = false;
            pixelCount++;
        }
    }

    imageStage_ += imageDiv_;

    if (imageStage_ == 2){
        imageDiv_ = -1;
    }

    if (imageStage_ == 0){
        imageDiv_ = 1;
    }

    show_();
}

void Matrix::showChanges(){
    show_();
}
/*!
 * PRIVATE FUNCTIONS
 */
CRGB Matrix::getRandomRGB_(){
    return CRGB(random(0, 150), random(0, 150), random(0, 150));
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

void Matrix::drawByCoordinates_(Point start, Point end){
    for (int i = start.y; i <= end.y; i++){
        for (int j = start.x; j <= end.x; j++){
            if (i < 16 && j < 16){
                leds_[getPixelNum_(Point(i,j))] = color_;
            }
        }
    }
}

void Matrix::drawXLine_(uint8_t x, uint8_t y, uint8_t size){
    for (int i = x; i < x + size; i++){
        if (i < 16 && y < 16){
            leds_[getPixelNum_(Point(y, i))] = color_;
        }
    }
}

void Matrix::drawYLine_(uint8_t x, uint8_t y, uint8_t size){
    for (int i = y; i < y + size; i++){
        if (i < 16 && x < 16){
            leds_[getPixelNum_(Point(i, x))] = color_;
        }
    }
}