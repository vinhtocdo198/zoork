//
// Created by FaZe-ltv on 5/23/2024.
//

#include "InsertLetterCommand.h"
#include <iostream>

#include "Bookshelf.h"
#include "Player.h"

void InsertLetterCommand::execute()
{
    const auto player = Player::instance();
    if (const auto currRoom = player->getCurrentRoom(); currRoom->getName() == "kid-bedroom")
    {
        const auto bookshelf = dynamic_cast<Bookshelf*>(currRoom->getItem("bookshelf"));

        std::cout << "You put letter '" << letter->getName() << "' on one of the book.\n";
        currRoom->getItem("bookshelf")->setDescription(bookshelf->getDescription() + ", " + letter->getName());

        // Add the letter to the bookshelf and delete from player's inventory
        Player::dropItem(letter->getName());
        bookshelf->addLetters(letter->getName());
        if (bookshelf->checkLetters())
        {
            bookshelf->setInteractive(true);
            bookshelf->setDescription(
                "A bookshelf, filled with children's books. All books on the top shelf have a letter on\n"
                "their spines. But it doesn't make any sense. What does '" + bookshelf->getMeaning() + "' even mean?");
        }
    }
    else
    {
        std::cout << "Nothing happens.\n";
    }
}
