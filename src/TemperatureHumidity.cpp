#include "TemperatureHumidity.h"
    
/// @brief Set up the sensor object to begin taking measurements and writing to I2C
void HDCSetup() {
    sensor.begin();
    sensor.reset();

    sensor.setMeasurementMode(TEMP_AND_HUMID);
    sensor.setRate(ONE_HZ);

    sensor.setTempRes(FOURTEEN_BIT);
    sensor.setHumidRes(FOURTEEN_BIT);
    sensor.triggerMeasurement();
}