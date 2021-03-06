/*
** EPITECH PROJECT, 2021
** hexer [WSL: Ubuntu-20.04]
** File description:
** Window
*/

#include <iostream>
#include "Window.hpp"
#include <cstring>
#include "Colors.hpp"

Window::Window(int height, int width, int hOffset, int wOffset)
{
    this->__win = subwin(stdscr, height, width, hOffset, wOffset);
    this->__internal.x = 0;
    this->__internal.y = 0;
    this->__currentOffset = 0;
    keypad(this->__win, TRUE);
    start_color();
    init_pair(SELECTED, COLOR_YELLOW, COLOR_BLACK);
    init_pair(MENU, COLOR_BLACK, COLOR_WHITE);
}

Window::~Window()
{
}

void Window::drawBorder(void) const {
    box(this->__win, ACS_VLINE, ACS_HLINE);
    return;
}

void Window::printString(const char *s) {
    for (uint32_t i = 0; s[i] != '\0'; i++) {
        if (s[i] == '\n') {
            this->__cursor.y = this->__cursor.y + 1;
            this->__cursor.x = 1;
        }
        else {
            mvwaddch(this->__win, this->__cursor.y, this->__cursor.x, s[i]);
            this->__cursor.x = this->__cursor.x + 1;
        }
    }
    return;
}

void Window::printVStringDec(const std::vector<uint8_t> &s)
{
    for (uint8_t c : s) {
        if (this->__cursor.x - 61 == this->__internal.x && this->__cursor.y - 2 == this->__internal.y) {
            wattron(this->__win, COLOR_PAIR(SELECTED));
            if (c < 32 || c > 126)
                mvwaddch(this->__win, this->__cursor.y, this->__cursor.x, '.');
            else
                mvwaddch(this->__win, this->__cursor.y, this->__cursor.x, c);
            wattroff(this->__win, COLOR_PAIR(SELECTED));
        }
        else {
            if (c < 32 || c > 126)
                mvwaddch(this->__win, this->__cursor.y, this->__cursor.x, '.');
            else
                mvwaddch(this->__win, this->__cursor.y, this->__cursor.x, c);
        }
        this->__cursor.x = this->__cursor.x + 1;
    }
    mvwaddch(this->__win, this->__cursor.y, this->__cursor.x, '\n');
    return;
}

void Window::printVStringHex(const std::vector<uint8_t> &s)
{
    for (uint8_t c : s) {
        if (this->__cursor.x - 11 == this->__internal.x * 3 && this->__cursor.y - 2 == this->__internal.y) {
            wattron(this->__win, COLOR_PAIR(SELECTED));
            mvwprintw(this->__win, this->__cursor.y, this->__cursor.x, "%02X", c);
            wattroff(this->__win, COLOR_PAIR(SELECTED));
        }
        else
            mvwprintw(this->__win, this->__cursor.y, this->__cursor.x, "%02X", c);
        this->__cursor.x = this->__cursor.x + 2;
        mvwprintw(this->__win, this->__cursor.y, this->__cursor.x, " ");
        this->__cursor.x = this->__cursor.x + 1;
    }
    mvwaddch(this->__win, this->__cursor.y, this->__cursor.x, '\n');
    return;
}

void Window::drawTopbar(void)
{
    this->__cursor.x = 1;
    this->__cursor.y = 1;
        wattron(this->__win, A_BOLD);
    wattron(this->__win, COLOR_PAIR(MENU));

    this->printString("Offset    00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F   strings from file\n");
            wattroff(this->__win, A_BOLD);

    wattroff(this->__win, COLOR_PAIR(MENU));
    return;
}

void Window::drawHex(const std::vector<std::vector<uint8_t>> &dump)
{
    char offset[11];

    for (uint64_t i = this->__currentOffset; i < this->__currentOffset + LINES - 3; i++) {
        memset((void *)offset, 0, 10);
        this->__cursor.x = 1;
        wattron(this->__win, COLOR_PAIR(MENU));
        wattron(this->__win, A_BOLD);
        sprintf(offset, "%08X ", (this->__currentOffset + i) * 16);
        this->printString(offset);
        wattroff(this->__win, A_BOLD);
        wattroff(this->__win, COLOR_PAIR(MENU));
        this->printString(" ");
        this->printVStringHex(dump.at(i));
        this->__cursor.x = this->__cursor.x + 2;
        this->printVStringDec(dump.at(i));
        this->__cursor.y = this->__cursor.y + 1;
    }
}

void Window::handleEvent(int currentKey)
{
/*
    if (currentKey == KEY_UP) {
        if (this->__currentOffset != 0) {
            if (this->__internal.y == 0)
                this->__currentOffset--;
            else
                this->__internal.y--;
        }
    }*/

    if (currentKey == KEY_UP) {
        
        if (this->__internal.y != 0) {
                this->__internal.y--;
        }
        else if (this->__internal.y == 0  && this->__currentOffset != 0)
            this->__currentOffset--;

    }
    if (currentKey == KEY_DOWN) {
        if (this->__internal.y == LINES - 5)
            this->__currentOffset++;
        else
            this->__internal.y++;

    }
    if (currentKey == KEY_RIGHT) {
        if (this->__internal.x < 15)
            this->__internal.x++;
    }
    if (currentKey == KEY_LEFT) {
        if (this->__internal.x != 0)
            this->__internal.x--;
    }
    return;
}

std::vector<uint8_t> Window::getNextBytes(std::vector<std::vector<uint8_t>> dump) const
{
    std::vector<uint8_t> bytes;
    Vector2 vec;

    vec.x = this->__internal.x;
    vec.y = this->__internal.y;
    for (int copied = 0; copied != 8; copied++) {
        bytes.push_back(dump.at(vec.y).at(vec.x));
        vec.x++;
        if (vec.x == 16) {
            vec.y++;
            vec.x = 0;
        }
    }
    return (bytes);
}