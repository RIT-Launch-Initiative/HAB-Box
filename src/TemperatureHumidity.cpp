#include "TemperatureHumidity.h"


/// @brief Set up the sensor object to begin taking measurements and writing to I2C
void HDCSetup(HDC2080 HDCsensor) {
    HDCsensor.begin();
    HDCsensor.reset();

    HDCsensor.setMeasurementMode(TEMP_AND_HUMID);
    HDCsensor.setRate(ONE_HZ);

    HDCsensor.setTempRes(FOURTEEN_BIT);
    HDCsensor.setHumidRes(FOURTEEN_BIT);
    HDCsensor.triggerMeasurement();
}
