//
// Created by FaZe-ltv on 5/22/2024.
//

#include "RemoveStitchesCommand.h"
#include "Player.h"
#include <iostream>

void RemoveStitchesCommand::execute()
{
    if (const auto player = Player::instance(); player->getCurrentRoom()->getName() == "kid-bedroom")
    {
        std::cout << "You cut the stitches and see a black [clock-hand].\n";
        player->getCurrentRoom()->getItem("teddy-bear")->setDescription(
            "A stuffed teddy bear, but it looks like a handful of cotton now.");
    }
    else
    {
        std::cout << "Nothing happens.\n";
    }
}
