#ifndef PIN_MAP_H
#define PIN_MAP_H

// --- I2C BUS (Shared: Camera, Audio, ToF, Gyro) ---
#define I2C_SDA         1
#define I2C_SCL         2

// --- SPI BUS (Shared: Screen, Touch, SD Slot) ---
#define SPI_MOSI        11
#define SPI_SCK         12
#define SPI_MISO        13

// --- DISPLAY (ILI9341) ---
#define TFT_CS          10
#define TFT_DC          9
#define TFT_RST         47 

// --- TOUCH (XPT2046) ---
#define TOUCH_CS        45  // Strapping Pin
#define TOUCH_IRQ       7

// --- SD CARD (Screen Slot) ---
#define SD_CS           14

// --- AUDIO CODEC (WM8960) ---
#define I2S_MCLK        18
#define I2S_BCLK        3   // Strapping Pin
#define I2S_WS          4
#define I2S_DIN         5
#define I2S_DOUT        6

// --- CAMERA (OV5640) ---
#define CAM_PCLK        8
#define CAM_XCLK        -1  // Set to -1 if using internal oscillator
#define CAM_HREF        16
#define CAM_VSYNC       21
#define CAM_D0          38
#define CAM_D1          39
#define CAM_D2          40
#define CAM_D3          41
#define CAM_D4          42
#define CAM_D5          43
#define CAM_D6          44
#define CAM_D7          46  // Strapping Pin

// --- SENSORS ---
#define TOF_INT         15
#define TOF_SHUT        48
#define GYRO_INT        17

#endif