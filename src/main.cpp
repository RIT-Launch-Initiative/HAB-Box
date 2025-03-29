#include <Arduino.h>
#include "PressureAltitude.h"

void setup() {
    Serial.begin(115200);
}

void loop() {
    delay(1000);
    if (!PressureAltitudeInit())
    {
        Serial.println("Failed to initialize pressure sensor.");
        return;
    }

    PressureAltitudeData_t data;
    if (!PressureAltitudeRead(data))
    {
        Serial.println("Failed to read pressure data.");
        return;
    }
    Serial.print("Pressure: ");
    Serial.print(data.pressure);
    Serial.print(" Temperature: ");
    Serial.print(data.temperature);
}