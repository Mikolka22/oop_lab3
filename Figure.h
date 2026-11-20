#pragma once

class System;

class Figure {
public:
    virtual ~Figure();
    virtual void show(System& console) = 0;
};
