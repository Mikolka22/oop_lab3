#include "Explosion.h"
#include "Symbol.h"

Explosion::Explosion(int column, int row, int limit, unsigned long long startTime) {
    x = column;
    y = row;
    maxRadius = limit;
    radius = -1;
    start = startTime;
}

bool Explosion::step(System& console, unsigned long long now) {
    if (now < start) return true;
    // Радиус увеличивается на одну клетку за 500 мс: 2 клетки в секунду.
    unsigned long long next = (now - start) / 500;
    if (next > static_cast<unsigned long long>(maxRadius)) return false;
    if (radius == static_cast<int>(next)) return true;
    radius = static_cast<int>(next);

    int count = 4 * radius;
    if (radius == 0) count = 1;
    for (int i = 0; i < count; ++i) {
        letters[i] = static_cast<char>(console.random(33, 126));
        colors[i] = console.random(1, 15);
    }
    return true;
}

void Explosion::show(System& console) {
    if (radius < 0) return;
    int i = 0;
    // Контур ромба: |dx| + |dy| = radius, как на первом рисунке задания.
    for (int dy = -radius; dy <= radius; ++dy) {
        int distance = dy;
        if (distance < 0) distance = -distance;
        int dx = radius - distance;
        Symbol left(x - dx, y + dy, letters[i], colors[i]);
        left.show(console);
        ++i;
        if (dx != 0) {
            Symbol right(x + dx, y + dy, letters[i], colors[i]);
            right.show(console);
            ++i;
        }
    }
}
