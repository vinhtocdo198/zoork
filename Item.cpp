//
// Created by Richard Skarbez on 5/7/23.
//

#include "Item.h"
#include "NullCommand.h"

Item::Item(const std::string& n, const std::string& d, const bool o, const bool i)
    : GameObject(n, d), obtainable(o), interactive(i), useCommand(std::make_shared<NullCommand>())
{
}

Item::Item(const std::string& n, const std::string& d, const bool o, const bool i, std::shared_ptr<Command> c)
    : GameObject(n, d), obtainable(o), interactive(i), useCommand(std::move(c))
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

void Item::setObtainable(const bool o)
{
    obtainable = o;
}

bool Item::isInteractive() const
{
    return interactive;
}

void Item::setInteractive(const bool i)
{
    interactive = i;
}

void Item::setUseCommand(std::shared_ptr<Command> c)
{
    useCommand = std::move(c);
}
