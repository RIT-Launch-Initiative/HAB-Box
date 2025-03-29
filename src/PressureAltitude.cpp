#include "PressureAltitude.h"

MS5x pressureSensor(&Wire);

bool PressureAltitudeInit() {
    int timeoutCount = 0;
    constexpr int maxTimeout = 5;

    while (timeoutCount <= maxTimeout)
    {
        if (pressureSensor.connect() > 0)
        {
            Serial.println("Connection timed out.");
            timeoutCount++;
            delay(200);
        }
    }
    if (timeoutCount >= maxTimeout)
    {
        Serial.println("Failed to connect to MS5607.");
        return false;
    }

    Serial.println("Connected to MS5607.");
    return true;
}

bool PressureAltitudeRead(PressureAltitudeData_t& data) {
    pressureSensor.checkUpdates();

    if (!pressureSensor.isReady())
        return false;
    
    data.pressure = pressureSensor.GetPres();
    data.temperature = pressureSensor.GetTemp();

    // calculate altitide
    // wip
    return true;
}