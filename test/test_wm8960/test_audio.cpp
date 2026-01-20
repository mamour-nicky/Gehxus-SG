#include <Arduino.h>
#include <Wire.h>
#include <driver/i2s.h> // Legacy driver compatible with Arduino Framework
#include <SparkFun_WM8960_Arduino_Library.h>
#include "PinMap.h"

WM8960 codec;

void setup_i2s_legacy() {
    i2s_config_t i2s_config = {
        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
        .sample_rate = 44100,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
        .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
        .communication_format = I2S_COMM_FORMAT_STAND_I2S,
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
        .dma_buf_count = 8,
        .dma_buf_len = 64,
        .use_apll = false
    };

    i2s_pin_config_t pin_config = {
        .mck_io_num = I2S_MCLK,
        .bck_io_num = I2S_BCLK,
        .ws_io_num = I2S_WS,
        .data_out_num = I2S_DOUT,
        .data_in_num = I2S_DIN
    };

    i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
    i2s_set_pin(I2S_NUM_0, &pin_config);
}

void setup() {
    Serial.begin(115200);
    Wire.begin(I2C_SDA, I2C_SCL);

    Serial.println("Initializing WM8960...");
    if (!codec.begin(Wire)) {
        Serial.println("WM8960 I2C Failed! Check pins 1 & 7.");
        while (1);
    }
    
    codec.enableHeadphones();
    codec.setHeadphoneVolume(50); 
    
    setup_i2s_legacy();
    Serial.println("I2S Legacy Driver Started.");
}

void loop() {
    // Heartbeat to confirm code is running
    Serial.println("Audio hardware initialized and waiting...");
    delay(5000);
}