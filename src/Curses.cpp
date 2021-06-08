/*
** KGTREY1 PROJECT, 2021
** hexer
** File description:
** Curses
*/

#include "Curses.hpp"

Curses::Curses() :
__x(COLS), __y(LINES)
{
    this->__win = initscr();
    noecho();
    curs_set(0);
    start_color();
    keypad(stdscr, TRUE);
    init_pair(1, COLOR_YELLOW, COLOR_GREEN);
}

Curses::~Curses() {
    endwin();
}

int Curses::getKey(void) const {
    int pressedKey = 0;

    pressedKey = wgetch(this->__win);
    if (pressedKey == ERR)
        throw "Error";
    return (pressedKey);
}