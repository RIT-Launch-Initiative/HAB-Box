#ifndef CONFIG_H
#define CONFIG_H

enum CardinalDirection : char
{
    North = 'N',
    East = 'E',
    South = 'S',
    West = 'W'
};

typedef struct {
    int profileNumber;
    int degrees;
    int minutes;
    double seconds;
    CardinalDirection direction;
    int radius;
    int altitude;
} Config;

bool LoadConfig();

const Config* GetConfig();

#endif