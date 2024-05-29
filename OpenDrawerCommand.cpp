//
// Created by FaZe-ltv on 5/23/2024.
//

#include "OpenDrawerCommand.h"
#include "Player.h"

void OpenDrawerCommand::execute()
{
    const auto player = Player::instance();
    std::cout << "You open the drawer.\n";
    drawer->setInteractive(false);
    drawer->setDescription("An opened drawer with some expired items, bandages, and a wooden piece\n"
        "of alphabetical letter [a] inside.");
    player->getCurrentRoom()->setDescription(
        "You are now in the bathroom. An opened [drawer] is in the corner, barely visible\n"
        "in the darkness. Below is a large [bathtub].\n");
}
