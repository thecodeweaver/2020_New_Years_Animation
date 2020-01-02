/*
 * 2020 New Years Animation
 * Start Date: Dec. 31, 2019 (My last Arduino sketch of 2019 and the decade!)
 * A New Years animation using a SSD1306 OLED display
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Bitmap.h"

// Some display constants
#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define OLED_RESET -1

// Let's setup our SSD1306 display
Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

void setup() 
{
    // put your setup code here, to run once:
    Serial.begin(115200);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println("Unable to setup SSD1306: allocation failed!");
        while (true)
            delay(5000);
    }

    display.display();
    display.clearDisplay();

    // Countdown
    for (int i = 10; i > 0; i--)
    {
        display.clearDisplay();
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.println(i);
        display.display();
        delay(1000);
    }

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Happy New Year!");
    display.display();
    delay(2000);

    // Show the fireworks
    display.clearDisplay();
    display.drawBitmap(0, 0, FIREWORKS, 128, 64, WHITE);
    display.display();
}

void loop() 
{
    // put your main code here, to run repeatedly:
}
