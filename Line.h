#pragma once
#include "Figure.h"
#include "Explosion.h"
#include <list>

class Line : public Figure {
    int x, length, color, number, speed;
    unsigned long long start;
    std::list<int> symbols;

    int getX(int n);
    int getY(int n);

public:
    Line(int column, int size, int textColor, int lineSpeed, unsigned long long startTime);
    bool step(System& console, unsigned long long now, int chance,
              int minRadius, int maxRadius, std::list<Explosion>& explosions);
    void show(System& console) override;
};
