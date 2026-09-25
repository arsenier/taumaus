#include <Arduino.h>

#include "drivers/driver_manager.hpp"

void setup()
{
  drivers::init();
}

void loop()
{
  drivers::motor_left.set_voltage(9.0);
  drivers::motor_right.set_voltage(9.0);
}
