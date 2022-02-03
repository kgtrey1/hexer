/*
** KGTREY1 PROJECT, 2021
** hexer
** File description:
** Hexer
*/

#include <unistd.h>
#include "Hexer.hpp"

Hexer::Hexer(const char *fileName) :
    __pageSize(16)
{
    std::string tmp;

    __file.open(fileName);
    if (!__file.is_open())
        throw "cannot open file";
    std::filebuf *buf = this->__file.rdbuf();
    this->__fileSize = buf->pubseekoff(0, this->__file.end);
    this->__fileContent = new char[this->__fileSize];
    buf->pubseekoff(0, this->__file.beg);
    buf->sgetn(this->__fileContent, this->__fileSize);
    this->parseFile();
    return;
}

Hexer::~Hexer()
{
    this->__file.close();
    delete[] this->__fileContent;
    return;
}

std::vector<unsigned char> Hexer::stringToCharVec(int64_t offset)
{
    std::vector<unsigned char> line;

    for (int64_t i = offset; i < this->__fileSize && i < offset + 16; i++)
        line.push_back((unsigned char)this->__fileContent[i]);
    return (line);
}


void Hexer::parseFile(void)
{
    std::vector<unsigned char> line;

    for (int64_t i = 0; i < this->__fileSize; i = i + 16)
        this->__dump.push_back(this->stringToCharVec(i));
    return;
}

void Hexer::dumpFile(void) const
{
    for (auto line: this->__dump) {
        for (unsigned char c : line)
            printf("%02X ", c);
        printf("\n");
    }
}

std::vector<std::vector<uint8_t>> Hexer::getDump(void) const
{
    return (this->__dump);
}