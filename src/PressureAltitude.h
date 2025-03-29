#ifndef PRESSURE_ALTITUDE_H
#define PRESSURE_ALTITUDE_H

#include <Arduino.h>
#include <Wire.h>
#include <MS5x.h>

typedef struct {
    double altitude;
    double pressure;
    double temperature;
} PressureAltitudeData_t;

bool PressureAltitudeInit();

bool PressureAltitudeRead(PressureAltitudeData_t& data);

#endif // PRESSURE_ALTITUDE_H