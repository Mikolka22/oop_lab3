#include "Line.h"
#include "Symbol.h"

Line::Line(int column, int size, int textColor, int lineSpeed, unsigned long long startTime) {
    x = column;
    length = size;
    color = textColor;
    number = 0;
    speed = lineSpeed;
    start = startTime;
}

int Line::getX(int n) {
    int dx[7] = {0, -1, 1, 0, -1, 1, 0};
    return x + dx[n % 7];
}

int Line::getY(int n) {
    int dy[7] = {0, 1, 1, 2, 3, 3, 4};
    return n / 7 * 5 + dy[n % 7];
}

bool Line::step(System& console, unsigned long long now, int chance,
                int minRadius, int maxRadius, std::list<Explosion>& explosions) {
    // Время каждого шага считаем от рождения линии, чтобы не копить задержку.
    while (now >= start + number * 1000ULL / speed) {
        unsigned long long time = start + number * 1000ULL / speed;
        symbols.push_back(number);
        if (static_cast<int>(symbols.size()) > length) symbols.pop_front();
        if (getY(symbols.front()) >= console.height) return false;

        // Вероятность chance/1000 проверяется один раз на каждый шаг линии.
        if (console.random(1, 1000) <= chance) {
            int radius = console.random(minRadius, maxRadius);
            explosions.emplace_back(getX(number), getY(number), radius, time);
            symbols.pop_back();
            --length;
        }
        ++number;
        if (length == 0) return false;
    }
    return true;
}

void Line::show(System& console) {
    // Храним номера оставшихся букв: взорванная голова больше не рисуется.
    for (int n : symbols) {
        char letter = 'A' + n % 26;
        Symbol symbol(getX(n), getY(n), letter, color);
        symbol.show(console);
    }
}
