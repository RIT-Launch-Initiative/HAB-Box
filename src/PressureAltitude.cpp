#include "PressureAltitude.h"
#include <MS56XX.h>

MS56XX sens(MS56XX_ADDR_LOW, MS5607);

bool PressureAltitudeInit() {
    if (!sens.begin()) 
        return false;
    
    sens.configBaro(BARO_PRESS_D1_OSR_4096, BARO_TEMP_D2_OSR_4096);
    return true; 
}

bool PressureAltitudeRead(PressureAltitudeData_t& data) {
    while (!sens.doBaro(true)) {
        delay(1);
    }
    
    data.pressure = sens.pressure;
    data.temperature = sens.temperature;
    data.altitude = sens.altitude;
    return true; // nyi
}