/*
** EPITECH PROJECT, 2021
** khexer [WSL: Ubuntu-20.04]
** File description:
** Typecaster
*/

#ifndef TYPECASTER_HPP_
#define TYPECASTER_HPP_

#include <ncurses.h>
#include <vector>
#include "Vector2.hpp"

class Typecaster {
    public:
        Typecaster(int height, int width, int hOffset, int wOffset);
        ~Typecaster();
        void drawBorder(void) const;
        void inspectData(std::vector<uint8_t> &bytes);
    private:
        void int8Inspection(std::vector<uint8_t> &bytes);
        void int16Inspection(std::vector<uint8_t> &bytes);
        void int32Inspection(std::vector<uint8_t> &bytes);
        void int64Inspection(std::vector<uint8_t> &bytes);
        WINDOW *__win;
        Vector2 __cursor;
};

#endif /* !TYPECASTER_HPP_ */
