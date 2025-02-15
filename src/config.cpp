#include "config.h"

#include <SPI.h>
#include <SD.h>
#include <cstring>
#include <Arduino.h>

#define MAX_CONF_SIZE 270

static char confFileBuf[MAX_CONF_SIZE];
File confFile;

static Config config = {};

bool LoadConfig() { 
    /// @todo change this to PIN_SPI_CS when Pin header ready
    if (!SD.begin(PIN_PA14)) 
        return false;
    
    confFile = SD.open("config.csv", FILE_READ);

    if (!confFile) 
        return false;
    
    confFile.read(confFileBuf, MAX_CONF_SIZE);

    confFile.close();

    // get profile number
    /// @todo replace with pin defs from pin header when ready
    int profile = 1; 
    int pins[4] = {PIN_PA17, PIN_PA19, PIN_PA08, PIN_PA09};
    char* line = 0;
    for (int i = 1; i <= 4; i++) {
        line = strstr(confFileBuf, "\n");
        if (line == nullptr)
            return false;
        line += 1;

        if (digitalRead(pins[i - 1]) == HIGH)
        {
            config.profileNumber = i;
            sscanf(confFileBuf, "%d* %d' %lf\" %c, %d, %d", 
                &(config.degrees), 
                &(config.minutes), 
                &(config.seconds), 
                &(config.direction), 
                &(config.radius), 
                &(config.altitude));

            break;
        }
    }

    return true;
}

const Config* GetConfig() {
    return &config;
}
