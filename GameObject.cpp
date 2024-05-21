//
// Created by Richard Skarbez on 5/7/23.
//

#include "GameObject.h"
#include <iostream>
#include <utility>

GameObject::GameObject(std::string n, std::string d) : name(std::move(n)), description(std::move(d))
{
}

void GameObject::setName(const std::string& s)
{
    name = s;
}

std::string GameObject::getName() const
{
    return name;
}

void GameObject::setDescription(const std::string& s)
{
    description = s;
}

std::string GameObject::getDescription() const
{
    return description;
}
