//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_GAMEOBJECT_H
#define ZOORK_GAMEOBJECT_H

#include <memory>
#include <iostream>

class GameObject
{
public:
    GameObject(std::string, std::string);

    std::string getName() const;

    void setName(const std::string&);

    std::string getDescription() const;

    void setDescription(const std::string&);

protected:
    std::string name;
    std::string description;
};

#endif // ZOORK_GAMEOBJECT_H
