#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <XPT2046_Touchscreen.h>
#include <SD.h>
#include "PinMap.h"

// Initialize objects
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
XPT2046_Touchscreen touch(TOUCH_CS, TOUCH_IRQ);

void setup() {
    Serial.begin(115200);
    while (!Serial);

    Serial.println("--- Starting SPI System Test ---");

    // 1. Initialize SPI Bus manually
    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);

    // 2. Test TFT Display
    Serial.print("Initializing TFT... ");
    tft.begin();
    tft.setRotation(1);
    tft.fillScreen(ILI9341_BLACK);
    tft.setTextColor(ILI9341_GREEN);
    tft.setTextSize(2);
    tft.setCursor(20, 20);
    tft.println("SPI System Online");
    Serial.println("OK!");

    // 3. Test SD Card
    Serial.print("Initializing SD Card... ");
    if (!SD.begin(SD_CS)) {
        Serial.println("FAILED (Check wiring/Card format)");
        tft.setTextColor(ILI9341_RED);
        tft.println("SD Card: FAILED");
    } else {
        Serial.println("OK!");
        tft.println("SD Card: OK");
    }

    // 4. Test Touch Controller
    Serial.print("Initializing Touch... ");
    if (!touch.begin()) {
        Serial.println("FAILED");
        tft.setTextColor(ILI9341_RED);
        tft.println("Touch: FAILED");
    } else {
        Serial.println("OK!");
        tft.setTextColor(ILI9341_GREEN);
        tft.println("Touch: OK. Try touching screen!");
    }
}

void loop() {
    if (touch.touched()) {
        TS_Point p = touch.getPoint();
        Serial.printf("Touch at X: %d, Y: %d\n", p.x, p.y);
        
        // Visual feedback on screen
        tft.fillCircle(map(p.x, 200, 3800, 0, 320), 
                       map(p.y, 200, 3800, 0, 240), 
                       2, ILI9341_YELLOW);
    }
    delay(10);
}