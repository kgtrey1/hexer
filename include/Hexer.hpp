/*
** KGTREY1 PROJECT, 2021
** hexer
** File description:
** Hexer
*/

#ifndef HEXER_HPP_
#define HEXER_HPP_

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

class Hexer {
    public:
        Hexer(const char *fileName);
        ~Hexer();
        void dumpFile(void) const;
    private:
        std::ifstream __file;
        std::streamsize __fileSize;
        std::vector<std::vector<unsigned char>> __parsedFile;
        int __pageSize;
        char *__fileContent;

        std::vector<unsigned char> stringToCharVec(uint64_t offset);
        void parseFile(void);
};

#endif /* !HEXER_HPP_ */