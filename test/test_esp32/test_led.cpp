#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixel(1, 48, NEO_GRB + NEO_KHZ800);

void setup() {
    pixel.begin();
}

void loop() {
    pixel.setPixelColor(0, pixel.Color(0, 255, 0)); // Green
    pixel.show();
    delay(500);
}