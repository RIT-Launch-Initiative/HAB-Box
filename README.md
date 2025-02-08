# HAB Box Avionics
Repo for the software that will be integrated into the High Altitude Balloon project.
# Purpose
The whole system will keep track of balloon location and perform certain actions based off sensor data.
# Hardware
Itsybitsy M0 Express with a custom made shield for addition capabilites.
The following are sensors and integrations that the shield and MCU will need and use:
- Barometric Altimeter
- Humidity and Temperature
- GPS (TinyGPS++)
- Servo ports
- Jumper Switches
- GPIO pins
- SD Card

# Output Format
The output of this software will be a csv file with the following format:
- Time, Latitude, Longitude, Altitude, Humidity, Temperature, Pressure, Altitude
Time, lat, long, and alt will be logged from GPS data, humidity and temp will be logged from sensor data, and pressure and altitude will be logged from the barometric altimeter.