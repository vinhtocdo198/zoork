//
// Created by FaZe-ltv on 5/23/2024.
//

#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include "Item.h"
#include <vector>

class Bookshelf : public Item
{
public:
    Bookshelf(const std::string&, const std::string&, bool, bool, std::vector<std::string>);

    Bookshelf(const std::string&, const std::string&, bool, bool, std::shared_ptr<Command>, std::vector<std::string>);

    bool checkLetters() const;

    void addLetters(const std::string&);

    std::string getMeaning();

protected:
    std::vector<std::string> letters;
};

#endif //BOOKSHELF_H
