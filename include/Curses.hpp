/*
** KGTREY1 PROJECT, 2021
** hexer
** File description:
** Curses
*/

#ifndef CURSES_HPP_
#define CURSES_HPP_

#include <curses.h>

class Curses {
    public:
        Curses();
        ~Curses();
        int getKey(void) const;
    private:
        WINDOW *__win;
        uint64_t __x;
        uint64_t __y;
};

#endif /* !CURSES_HPP_ */