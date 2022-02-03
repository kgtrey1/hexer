/*
** EPITECH PROJECT, 2021
** khexer [WSL: Ubuntu-20.04]
** File description:
** Typecaster
*/

#include <ncurses.h>
#include "Typecaster.hpp"

Typecaster::Typecaster(int height, int width, int hOffset, int wOffset)
{
    this->__win = subwin(stdscr, height, width, hOffset, wOffset);
}

Typecaster::~Typecaster()
{
}

void Typecaster::drawBorder(void) const {
    box(this->__win, ACS_VLINE, ACS_HLINE);
    return;
}

void Typecaster::int64Inspection(std::vector<uint8_t> &bytes)
{
    __int128_t value = 0;

    if (bytes.size() < 8)
        return;
    value = __int128_t(bytes.at(0) << 56   |
                    bytes.at(1) << 48   | 
                    bytes.at(2) << 40   |
                    bytes.at(3) << 32   |
                    bytes.at(4) << 24   |
                    bytes.at(5) << 16   |
                    bytes.at(6) << 8    |
                    bytes.at(7) << 0);
    mvwprintw(this->__win, this->__cursor.y, this->__cursor.x, "Int64: %ld\n", value);
    this->__cursor.x = 1;
    this->__cursor.y++;
    return;
}

void Typecaster::int32Inspection(std::vector<uint8_t> &bytes)
{
    int32_t value = 0;

    if (bytes.size() < 4)
        return;
    value = int32_t(bytes.at(0) << 24   |
                    bytes.at(1) << 16   |
                    bytes.at(2) << 8    |
                    bytes.at(3) << 0);
    mvwprintw(this->__win, this->__cursor.y, this->__cursor.x, "Int32: %d\n", value);
    this->__cursor.x = 1;
    this->__cursor.y++;
    return;
}

void Typecaster::int16Inspection(std::vector<uint8_t> &bytes)
{
    int16_t value = 0;

    if (bytes.size() < 2)
        return;
    value = int16_t(bytes.at(0) << 8    |
                    bytes.at(1) << 0);
    mvwprintw(this->__win, this->__cursor.y, this->__cursor.x, "Int16: %hd\n", value);
    this->__cursor.x = 1;
    this->__cursor.y++;
    return;
}

void Typecaster::int8Inspection(std::vector<uint8_t> &bytes)
{
    int8_t value = 0;

    if (bytes.size() < 1)
        return;
    value = int8_t(bytes.at(0) << 0);
    mvwprintw(this->__win, this->__cursor.y, this->__cursor.x, "Int8: %d\n", value);
    this->__cursor.x = 1;
    this->__cursor.y++;
    return;
}

void Typecaster::inspectData(std::vector<uint8_t> &bytes)
{
    this->__cursor.x = 1;
    this->__cursor.y = 1;
    mvwprintw(this->__win, this->__cursor.y, this->__cursor.x, "Inspector\n");
    this->__cursor.x = 1;
    this->__cursor.y+=2;
    this->int8Inspection(bytes);
    this->int16Inspection(bytes);
    this->int32Inspection(bytes);
    this->int64Inspection(bytes);
    return;
}