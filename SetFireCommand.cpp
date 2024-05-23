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
    foyer->setDescription("The foyer looks brighter now. In front of you is a cold corridor\n"
        "and on your left is a spiral staircase, Italian style.\n");
    Passage::createBasicPassage(foyer, living_room, "north", true);
    Passage::createBasicPassage(foyer, piano, "up", true);
}
