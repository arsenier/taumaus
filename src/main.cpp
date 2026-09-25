#include <Arduino.h>

#include "drivers/driver_manager.hpp"

void setup()
{
  drivers::init();

  Serial.begin(115200);
}

void loop()
{
  drivers::motor_left.set_voltage(0.0);
  drivers::motor_right.set_voltage(0.0);

  Serial.println(drivers::battery_volts_driver.get_volts());
  delay(100);
}
