#include "config.h"

#define SD_FAT_TYPE 3 // fat16, fat32, and exfat
#define SPI_SPEED SD_SCK_MHZ(50)
#define ENABLE_DEDICATED_SPI 1

#include <SPI.h>
#include <SdFat.h>
#include <cstring>
#include <Arduino.h>
#include "pin.h"

#define MAX_CONF_SIZE 270

static char confFileBuf[MAX_CONF_SIZE];
static SdFs sd;
static FsFile confFile;

static Config config = {};

void ScanLine(const char* buf, Config& config, int profile) {
    config.profileNumber = profile;
    sscanf(buf, "%d* %d' %lf\" %c, %d, %d", 
        &(config.degrees), 
        &(config.minutes), 
        &(config.seconds), 
        (char*)&(config.direction), 
        &(config.radius), 
        &(config.altitude));
}

bool LoadConfig() { 
    /// @todo change this to PIN_SPI_CS when Pin header ready

    if (!sd.begin(PIN_PA14, SPI_SPEED)) 
    {
        Serial.print("SD card initialization failed: ");
        Serial.print(sd.card()->errorCode());
        Serial.print(" ");
        Serial.println(sd.card()->errorData());
        return false;
    }
    
    confFile = sd.open("config.csv", FILE_READ);

    if (!confFile) 
    {
        Serial.println("Cannot open config.csv for reading.");
        return false;
    }
    
    confFile.read(confFileBuf, MAX_CONF_SIZE);
    confFile.close();

    if (confFileBuf == nullptr) {
        Serial.println("Config file is empty.");
        return false;
    }

    // get profile number
    /// @todo replace with pin defs from pin header when ready
    bool populated = false; 
    int pins[4] = {PIN_PA17, PIN_PA19, PIN_PA08, PIN_PA09};
    char* line = strstr(confFileBuf, "\n") + 1; // skip comment
    if (line == nullptr) {
        Serial.println("No configs found.");
        return false;
    }

    for (int i = 1; i <= 4; i++) {
        line = strstr(line, "\n") + 1;
        if (line == nullptr)
            break;
        line += 1;

        if (digitalRead(pins[i - 1]) == HIGH)
        {
            ScanLine(line, config, i);
            populated = true;
            break;
        }
    }

    // no jumper pin, default to first line
    if (!populated) {
        Serial.println("No jumper detected. Defaulting to first profile.");
        ScanLine(line, config, 1);
    }

    return true;
}

const Config* GetConfig() {
    return &config;
}
