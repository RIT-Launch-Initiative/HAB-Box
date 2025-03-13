#include <Arduino.h>
#include "config.h"

void setup() {
    Serial.begin(115200);

}

void loop() {
    bool balls = LoadConfig();
    Serial.println(balls ? "true" : "false");
    delay(1000);
}