//
// Created by Richard Skarbez on 5/7/23.
//

#include "Item.h"
#include "NullCommand.h"
#include <utility>

Item::Item(const std::string& n, const std::string& d, const bool obtainable)
    : GameObject(n, d), obtainable(obtainable), useCommand(std::make_shared<NullCommand>())
{
}

Item::Item(const std::string& n, const std::string& d, const bool obtainable, std::shared_ptr<Command> c)
    : GameObject(n, d), obtainable(obtainable), useCommand(std::move(c))
{
}

void Item::use()
{
    useCommand->execute();
}

bool Item::isObtainable() const
{
    return obtainable;
}

void Item::setUseCommand(std::shared_ptr<Command> c)
{
    useCommand = std::move(c);
}
