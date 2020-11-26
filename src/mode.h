#ifndef __MODE_H
#define __MODE_H

#define MODE_PIN 2

bool mode = false; //false means transmitting
int selectedSlot = 0;

void setup_mode()
{
  pinMode(MODE_PIN, OUTPUT);
}

void toggle_mode()
{
  mode = !mode;
  digitalWrite(MODE_PIN, mode ? LOW : HIGH);
}

bool is_transmitting()
{
  return !mode;
}

bool is_recording()
{
  return !!mode;
}

void increment_slot()
{
  if (++selectedSlot > 5)
    selectedSlot = 0;
}

#endif __MODE_H