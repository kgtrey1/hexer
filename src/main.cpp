/*
** KGTREY1 PROJECT, 2021
** hexer
** File description:
** main
*/

#include "Hexer.hpp"

int main(int ac, const char **av)
{
    Hexer hex(av[1]);

    std::cout << "start of dump\n" << std::endl;
    hex.dumpFile();
    return (0);
}