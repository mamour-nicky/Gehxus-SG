#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define RGB_BRIGHTNESS 50 // 0-255
#define PIN_RGB_LED 48    // Pin 48 is standard for ESP32-S3 DevKitC-1

Adafruit_NeoPixel pixel(1, PIN_RGB_LED, NEO_GRB + NEO_KHZ800);

// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(115200);
  pixel.begin();
  pixel.setBrightness(RGB_BRIGHTNESS);
  Serial.println("ESP32-S3 RGB Test Started");
}

void loop() {
  pixel.setPixelColor(0, pixel.Color(0, 255, 0)); // Green
  pixel.show();
  delay(500);
  pixel.setPixelColor(0, pixel.Color(0, 0, 0));   // Off
  pixel.show();
  delay(500);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}