/*
** KGTREY1 PROJECT, 2021
** hexer
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <ncurses.h>
#include <vector>
#include "Vector2.hpp"

class Window {
    public:
        Window(int height, int width, int hOffset, int wOffset);
        ~Window();
        void drawBorder(void) const;
        void printString(const char *s);
        void printVStringDec(const std::vector<uint8_t> &s);
        void printVStringHex(const std::vector<uint8_t> &s);
        void drawTopbar(void);
        void drawHex(const std::vector<std::vector<uint8_t>> &dump);

    private:
        WINDOW *__win;
        struct Vector2 __cursor;
        struct Vector2 __internal;
        int64_t __currentOffset;
};

#endif /* !WINDOW_HPP_ */