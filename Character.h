//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_CHARACTER_H
#define ZOORK_CHARACTER_H

#include "GameObject.h"

class Character : public GameObject
{
public:
    Character(const std::string&, const std::string&);
};

#endif // ZOORK_CHARACTER_H
