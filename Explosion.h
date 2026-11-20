#pragma once
#include "Figure.h"

class Explosion : public Figure {
    int x, y, radius, maxRadius;
    int colors[40];
    char letters[40];
    unsigned long long start;

public:
    Explosion(int column, int row, int limit, unsigned long long startTime);
    bool step(System& console, unsigned long long now);
    void show(System& console) override;
};
