#ifndef OLED_H
#define OLED_H

//#include <Adafruit_Sensor.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "mode.h"

Adafruit_SSD1306 display(LED_BUILTIN);

void setup_oled()
{

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.display();

  display.setTextSize(2);
  display.setTextColor(WHITE);
}

void loop_oled()
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(is_recording() ? "< Record >" : "<Transmit>");
  display.setCursor(0, 18);

  display.print('(');
  display.print(selectedSlot);
  display.print(") ");

  switch (selectedSlot)
  {
  case 0:
    display.print("mute");
    break;
  case 1:
    display.print("off");
    break;
  case 2:
    display.print("do *");
    break;
  case 3:
    display.print("up *");
    break;
  case 4:
    display.print("mute *");
    break;
  case 5:
    display.print("off *");
    break;
  }

  display.display();
}

#endif