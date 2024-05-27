//
// Created by FaZe-ltv on 5/22/2024.
//

#include "InstallClockHandCommand.h"
#include "Player.h"

void InstallClockHandCommand::execute()
{
    if (const auto player = Player::instance(); player->getCurrentRoom()->getName() == "living-room")
    {
        Player::dropItem("clock-hand");
        std::cout <<
            "You install the watch hand on the clock. \"Cuckoo!\" The hands start to spin and stop after a while.\n";
        clock->setDescription("A cuckoo clock mounted on the wall, hands pointing to 18:09.");
    }
    else
    {
        std::cout << "Nothing happens.\n";
    }
}
