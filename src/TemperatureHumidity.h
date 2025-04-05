#ifndef TEMPERATUREHUMIDITY_H
#define TEMPERATUREHUMIDITY_H

#include <HDC2080.h>

#define ADDR 0x40           // Define the address of the chip

/// @brief Set up the sensor object to begin taking measurements and writing to I2C
void HDCSetup(HDC2080 HDCsensor);

#endif