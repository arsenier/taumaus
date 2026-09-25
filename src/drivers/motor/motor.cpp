#include "motor.hpp"

#include <Arduino.h>

namespace drivers::motor
{
    void MotorDriver::init()
    {
        pinMode(dir_pin, OUTPUT);
        pinMode(pwm_pin, OUTPUT);
    }

    void MotorDriver::set_voltage(float u)
    {
        digitalWrite(dir_pin, (u > 0) ^ polarity);

        int pwm = constrain(abs(u) / get_voltage() * 255, 0, 255);

        analogWrite(pwm_pin, pwm);
    }

}; // namespace drivers::motor

/*

u>0 |p  | ^
0   |0  | 0
1   |0  | 1
0   |1  | 1
1   |1  | 0

*/
