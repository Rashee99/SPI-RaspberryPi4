# SPI-RaspberryPi4

from PIL import Image

import Adafruit_ILI9341 as TFT
import Adafruit_GPIO as GPIO
import Adafruit_GPIO.SPI as SPI

# Raspberry Pi configuration.
DC = 18
RST = 23
SPI_PORT = 0
SPI_DEVICE = 0

# Create TFT LCD display class.
disp = TFT.ILI9341(DC, rst=RST, spi=SPI.SpiDev(SPI_PORT, SPI_DEVICE, max_speed_hz=64000000))

# Initialize display.
disp.begin()

# Load an image.
print('Loading image...')
image = Image.open('ai.jpg') # Your jpg file name

# Resize the image and rotate it so it's 240x320 pixels.
image = image.rotate(90).resize((240,320))

# Draw the image on the display hardware.
print('Drawing image')
disp.display(image)
