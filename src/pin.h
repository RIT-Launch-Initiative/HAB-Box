///
/// File for defining pin headers and pin modes
/// Author: Chloe Clark

#include <variant.h>
#include <Arduino.h>

#define GPIO1 A0
#define GPIO2 A1
#define GPIO3 A2
#define GPIO4 A3
#define GPIO5 A4
#define TEMPINT A5

#define PROG1 13
#define PROG2 12

#define PWM1 11
#define PWM2 10
#define PWM3 A11

#define GPIO6 7
#define GPIO7 5

#define SCL 27
#define SDA 26

#define TX A7
#define RX A6
#define PROG3 A8
#define PROG4 A9

inline void pinMode(uint32_t pin, uint32_t mode) {
    pinMode(pin, mode);
}

