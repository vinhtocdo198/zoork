//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_ITEM_H
#define ZOORK_ITEM_H

#include "Command.h"
#include "GameObject.h"

class Item : public GameObject
{
public:
    virtual ~Item() = default;

    Item(const std::string&, const std::string&, bool, bool);

    Item(const std::string&, const std::string&, bool, bool, std::shared_ptr<Command>);

    virtual void use();

    bool isObtainable() const;

    void setObtainable(bool);

    bool isInteractive() const;

    void setInteractive(bool);

    void setUseCommand(std::shared_ptr<Command>);

protected:
    bool obtainable;
    bool interactive;
    std::shared_ptr<Command> useCommand;
};

#endif // ZOORK_ITEM_H
