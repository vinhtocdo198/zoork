//
// Created by FaZe-ltv on 5/23/2024.
//

#include "Bookshelf.h"
#include <iostream>
#include <utility>

Bookshelf::Bookshelf(const std::string& n, const std::string& d, const bool a, const bool s, std::vector<std::string> l)
    : Item(n, d, a, s), letters(std::move(l))
{
}

Bookshelf::Bookshelf(const std::string& n, const std::string& d, const bool a, const bool s, std::shared_ptr<Command> c,
                     std::vector<std::string> l)
    : Item(n, d, a, s, std::move(c)), letters(std::move(l))
{
}

bool Bookshelf::checkLetters() const
{
    return letters.size() == 7;
}

void Bookshelf::addLetters(const std::string& lName)
{
    letters.push_back(lName);
}

std::string Bookshelf::getMeaning()
{
    std::string meaning;
    for (const auto& l : letters)
    {
        meaning += l;
    }
    return meaning;
}
