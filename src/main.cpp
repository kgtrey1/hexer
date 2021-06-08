/*
** KGTREY1 PROJECT, 2021
** hexer
** File description:
** main
*/

#include "Hexer.hpp"
#include "Curses.hpp"
#include "Window.hpp"

int main(__attribute((unused))int ac, const char **av)
{
    int currentKey = 0;
    Hexer hex(av[1]);
    std::vector<std::vector<uint8_t>> hexdump = hex.getDump();
    Curses ncurses;
    Window hexView(LINES - 1, 82, 0, 0);

    do {
        clear();
        hexView.handleEvent(currentKey);
        hexView.drawTopbar();
        hexView.drawHex(hexdump);
        hexView.drawBorder();
        refresh();
        currentKey = getch();
    }
    while (currentKey != 'q' && currentKey != 'Q');
    return (0);
}