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


# Configuration
By default, if no jumpers are shorted on the shield, profile 1 will be used.
At least 1 profile must be specified after the format comment line. 
The configuraton file has the following format:

**config.csv**
```csv
# format: latitutde, longitude, radius, altitude
lat1, lon1, rad1, alt1
lat2, lon2, rad2, alt2
lat3, lon3, rad3, alt3
lat4, lon4, rad4, alt4
```


- `latN` is profile `N`'s geofence center latitude in degrees, minutes, and seconds. It has a format `ddd* mm' ss" c`. `ddd*` is 3 digits of degrees, `mm'` is 2 digits of minutes, `ss"` is 2 digits of seconds, and `c` for its cardinal direction (N/S).
- `lonN` is profile `N`'s geofence center longitude in degrees, minutes, and seconds. It has a format `ddd* mm' ss" c`. `ddd*` is 3 digits of degrees, `mm'` is 2 digits of minutes, `ss"` is 2 digits of seconds, and `c` for its cardinal direction (E/W).
- `radN` is profile `N`'s geofence radius in meters. It has a format `mmmm`, 4 digits for meters.
- `altN` is profile `N`'s drop altitude in meters. It has a format `mmmmm`, 5 digits for meters.

