#pragma once
#include <string>

class System;

class AppManager {
    int frequency, speed, length;
    int chance, minRadius, maxRadius;
    bool colorful;

    int number(std::string text, int min, int max);
    int readNumber(const char* prompt, int min, int max);
    void makeTimes(System& console, int times[]);

public:
    int run(int argc, char* argv[]);
};
