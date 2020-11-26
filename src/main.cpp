#include <Arduino.h>

#include "mode.h"
#include "oled.h"
#include "ir.h"

#define BUTTON_PIN_1 11
#define BUTTON_PIN_2 12

void setup()
{
  Serial.begin(115200);
  pinMode(BUTTON_PIN_1, INPUT);
  pinMode(BUTTON_PIN_2, INPUT);

  setup_mode();
  setup_oled();
  setup_ir();
}

int buttonState1 = 0;
int buttonState2 = 0;

int prevButton1 = 0;
int prevButton2 = 0;

bool first()
{
  return prevButton1 == HIGH && buttonState1 == LOW;
}
bool second()
{
  return prevButton2 == HIGH && buttonState2 == LOW;
}
bool both()
{
  return first() && second();
}

void loop()
{
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(BUTTON_PIN_1);
  buttonState2 = digitalRead(BUTTON_PIN_2);

  if (both())
  {
    toggle_mode();
  }
  else if (second())
  {
    increment_slot();
  }
  else if (is_transmitting() && first())
  {
    send_test();
  }

  prevButton1 = buttonState1;
  prevButton2 = buttonState2;

  loop_oled();
}
