#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdint.h>
#include <unistd.h>

#define TFT_SPI_CHANNEL 0
#define TFT_SPI_SPEED   64000000 // 64MHz SPI speed
#define TFT_DC_PIN      18       // GPIO pin connected to DC
#define TFT_RESET_PIN   23       // GPIO pin connected to RESET

// ILI9341 commands
#define ILI9341_RESET          0x01
#define ILI9341_DISPLAY_ON     0x29
#define ILI9341_MEMORY_WRITE   0x2C

void sendCommand(uint8_t cmd) {
    digitalWrite(TFT_DC_PIN, LOW);
    wiringPiSPIDataRW(TFT_SPI_CHANNEL, &cmd, 1);
}

void sendData(uint8_t data) {
    digitalWrite(TFT_DC_PIN, HIGH);
    wiringPiSPIDataRW(TFT_SPI_CHANNEL, &data, 1);
}

void setCursorPosition(uint16_t x, uint16_t y) {
    sendCommand(0x2A); // Column Address Set
    sendData(x >> 8);
    sendData(x & 0xFF);
    sendData((x + 1) >> 8);
    sendData((x + 1) & 0xFF);

    sendCommand(0x2B); // Row Address Set
    sendData(y >> 8);
    sendData(y & 0xFF);
    sendData((y + 1) >> 8);
    sendData((y + 1) & 0xFF);
}

void drawPixel(uint16_t x, uint16_t y, uint16_t color) {
    setCursorPosition(x, y);
    sendCommand(ILI9341_MEMORY_WRITE);
    sendData(color >> 8);
    sendData(color & 0xFF);
}

void initializeTFT() {
    pinMode(TFT_DC_PIN, OUTPUT);
    pinMode(TFT_RESET_PIN, OUTPUT);

    digitalWrite(TFT_RESET_PIN, LOW);
    usleep(10000);
    digitalWrite(TFT_RESET_PIN, HIGH);
    usleep(10000);

    sendCommand(ILI9341_RESET);
    usleep(100000);

    sendCommand(ILI9341_DISPLAY_ON);

    setCursorPosition(0, 0);
}

void drawName() {
    // Draw "Rashee Wijesinghe"
    uint16_t textColor = 0xF800; // Red color, adjust as needed

    // Draw "Rashee"
    drawPixel(10, 10, textColor);
    drawPixel(20, 10, textColor);
    drawPixel(30, 10, textColor);
    drawPixel(40, 10, textColor);
    drawPixel(50, 10, textColor);

    // Draw "Wijesinghe"
    drawPixel(10, 30, textColor);
    drawPixel(20, 30, textColor);
    drawPixel(30, 30, textColor);
    drawPixel(40, 30, textColor);
    drawPixel(50, 30, textColor);
    drawPixel(60, 30, textColor);
    drawPixel(70, 30, textColor);
    drawPixel(80, 30, textColor);
    drawPixel(90, 30, textColor);
    drawPixel(100, 30, textColor);
}

int main() {
    if (wiringPiSetup() == -1)
        return 1;

    if (wiringPiSPISetup(TFT_SPI_CHANNEL, TFT_SPI_SPEED) == -1)
        return 1;

    initializeTFT();

    // Draw Name
    drawName();

    return 0;
}
