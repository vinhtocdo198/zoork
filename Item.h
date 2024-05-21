//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_ITEM_H
#define ZOORK_ITEM_H

#include "Command.h"
#include "GameObject.h"
#include <memory>

class Item : public GameObject
{
public:
    virtual ~Item() = default;

    Item(const std::string&, const std::string&, bool);

    Item(const std::string&, const std::string&, bool, std::shared_ptr<Command>);

    virtual void use();

    bool isObtainable() const;

    void setObtainable(bool);

    void setUseCommand(std::shared_ptr<Command>);

protected:
    bool obtainable;
    bool inUse = false;
    std::shared_ptr<Command> useCommand;
};

#endif // ZOORK_ITEM_H
