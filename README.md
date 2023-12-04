# SPI-RaspberryPi4
INTERFACING RASPBERRY PI 4 WITH TFT DISPLAY USING SPI AND PROGRAMMING WITH C AND PYTHON

# Raspberry Pi Setup Guide

## 1. Get the Necessary Hardware
- Raspberry Pi 4 board (with power supply)
- MicroSD card and SD card reader (at least 8GB recommended)
- Micro HDMI cable
- Monitor
- USB keyboard and mouse

## 2. Installing OS to the Raspberry Pi 4 Board
1. Download the [Raspberry Pi Imager](https://www.raspberrypi.org/software/) and install the software.
2. Connect the SD card to the PC using an SD card reader.
3. Open the software, and it will look like the following:

![Writing](https://github.com/Rashee99/SPI-RaspberryPi4/assets/87062307/ecc897c0-5d46-4c4b-b124-fc1e845c2b61)

Raspberry Pi Device: Raspberry Pi 4
- Operating System: Raspberry Pi OS (64 bit)
- Storage: Choose your SD card

## Initial Setup Steps

1. **Flash the OS to SD Card**
   
2. **Connect the Raspberry Pi Board**
   - Insert the SD card into the Raspberry Pi Board.
   - Connect the board to the monitor using an HDMI cable.
   - Connect a mouse and keyboard to the board.

3. **Power Up the Board**
   - Use the provided power supply to power up the Raspberry Pi.

4. **Configuration Setup**
   - Configure country, language, time zone, and keyboard layout.
   - Set the username to "pi" (if using "pi", avoid the old default password "password").

5. **Connect to WiFi**
   - Configure and connect to your WiFi network.

6. **Choose Default Internet Browser**
   - Select either Firefox or Chromium as your default internet browser.

7. **Update Operating System and Software**
   - Update your operating system and software to the latest versions.

8. **Reboot Raspberry Pi**
   - Click "Restart" to reboot your Raspberry Pi.

## Raspberry Pi Configuration Tool

9. **Open Raspberry Pi Configuration**
   - Access the Raspberry Pi Configuration tool using the following steps:

![Config](https://github.com/Rashee99/SPI-RaspberryPi4/assets/87062307/adb584da-095d-41a5-b18e-772df3f9fb3f)

  - Enable the SSH, and SPI settings.

![SPI](https://github.com/Rashee99/SPI-RaspberryPi4/assets/87062307/d70c1765-88ed-4c29-82e5-b7d511fa4f3c)

- Check if the SPI configuration is unable or not using ls /dev (spidev0.0 and spidev0.1 must be there).

## 4.	Connect Raspberry Pi board to PC
-	Check the IP address of the Raspberry Pi board using: ip a
-	Open the putty software in your PC and connect to Board using IP address.
-	Log in to board using username and password

## 5.	Interfacing ILI9341 TFT display with Raspberry Pi Board

![wiring1](https://github.com/Rashee99/SPI-RaspberryPi4/assets/87062307/97e9debb-542b-4c83-b435-33444c03e5a7)

![wiring2](https://github.com/Rashee99/SPI-RaspberryPi4/assets/87062307/597512c8-ff0d-487b-81f9-28a5bc94cd3f)

# Raspberry Pi and ILI9341 TFT Display Wiring

| TFT Display Pin | Raspberry Pi Pin | Raspberry Pi Function |
|-----------------|-------------------|------------------------|
| LED             | 1 (3V3 Power)     | Power                  |
| SCK             | 23 (GPIO11 SCLK)  | Serial Clock           |
| SDA             | 19 (GPIO10 MOSI)  | Serial Data            |
| AO              | 12 (GPIO18 PWM_CLK) | PWM Clock             |
| RESET           | 16 (GPIO23)        | Reset                  |
| CS              | 24 (GPIO8 CE0)     | Chip Select (CE0)      |
| GND             | 6 (GND)            | Ground                 |
| VCC             | 2 (5V)             | Power (5V)             |





