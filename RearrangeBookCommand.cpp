//
// Created by FaZe-ltv on 5/23/2024.
//

#include "RearrangeBookCommand.h"
#include "Player.h"
#include <iostream>

void RearrangeBookCommand::execute()
{
    const auto player = Player::instance();
    const auto bookshelf = player->getCurrentRoom()->getItem("bookshelf");
    std::string keyword;
    std::cout << "You try to rearrange the order of the books.\n";
    bool activated = false;
    while (!activated)
    {
        std::cout << "Enter the keyword (or 'q' to exit):";
        std::getline(std::cin, keyword);

        if (keyword == "q")
        {
            std::cout << "You stop trying to rearrange the order of the books.\n";
            break;
        }

        if (keyword == "monalisa")
        {
            std::cout << "Smash! The sound comes from downstairs.\n";
            activated = true;
        }
        else
        {
            std::cout << "Nothing happens.\n";
        }
    }

    if (activated)
    {
        bookshelf->setInteractive(false);
        bookshelf->setDescription("A bookshelf filled with children's books. The letters on the spines of the books\n"
            "on the top shelf form the word 'cse3psd'.");
        living_room->setDescription("You are now in the living room. A corridor leads to the kitchen to the north.\n"
            "A worn-out [sofa] is in the middle, facing a vintage [TV]. Above the TV, a [clock]\n"
            "and... the [painting] is broken and lying on the floor, leaving a [hole] in the wall.\n");
        living_room->getItem("painting")->setDescription("Shattered glass of the Mona Lisa painting.");
    }
}
