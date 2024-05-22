//
// Created by FaZe-ltv on 5/22/2024.
//

#include "SetFireCommand.h"
#include "Passage.h"
#include <iostream>
#include "Player.h"

void SetFireCommand::execute()
{
    if (const auto player = Player::instance(); player->getCurrentRoom()->getName() == "front-yard")
    {
        std::cout << "Nothing happens.\n";
        return;
    }
    std::cout << "You set fire to the oil lamp.\n";
    oil_lamp->setObtainable(true);
    oil_lamp->setDescription("An oil lamp that is on fire.");
}
