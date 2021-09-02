#include "Resources.h"

Resources::Resources(void) {
    w = h = s = b = o = 0;
}

int Resources::get(char c) {
    if (c == 'w')
        return w;
    else if (c == 'h')
        return h;
    else if (c == 's')
        return s;
    else if (c == 'b')
        return b;
    else if (c == 'o')
        return o;
    else
        return -1;
}

void Resources::add(char c) {
    if (c == 'w')
        w++;
    if (c == 'h')
        h++;
    if (c == 's')
        s++;
    if (c == 'b')
        b++;
    if (c == 'o')
        o++;
}

void Resources::remove(char c, int n) {
    if (c == 'w')
        w -= n;
    if (c == 'h')
        h -= n;
    if (c == 's')
        s -= n;
    if (c == 'b')
        b -= n;
    if (c == 'o')
        o -= n;
}

void Resources::display(void) {
    std::cout << std::setw(4) << "w"
              << std::setw(4) << "b"
              << std::setw(4) << "h"
              << std::setw(4) << "s"
              << std::setw(4) << "o" << std::endl;
    std::cout << std::setw(4) << w
              << std::setw(4) << b
              << std::setw(4) << h
              << std::setw(4) << s
              << std::setw(4) << o << std::endl;
}