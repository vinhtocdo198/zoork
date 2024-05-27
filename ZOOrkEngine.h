//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_ZOORKENGINE_H
#define ZOORK_ZOORKENGINE_H

#include "Player.h"
#include "Location.h"
#include "Passage.h"

class ZOOrkEngine
{
public:
    explicit ZOOrkEngine(const std::shared_ptr<Room>&);

    void run();

    // void setGameOver() const;

private:
    bool gameOver = false;

    Player* player;

    bool firstEnter = false;

    void handleGoCommand(const std::vector<std::string>&) const;

    void handleLookCommand(const std::vector<std::string>&) const;

    void handleTakeCommand(const std::vector<std::string>&) const;

    void handleDropCommand(const std::vector<std::string>&) const;

    void handleInteractCommand(const std::vector<std::string>&);

    static void handleUseCommand(const std::vector<std::string>&);

    static void handleInventoryCommand();

    void handleQuitCommand(const std::vector<std::string>&);

    static std::vector<std::string> tokenizeString(const std::string&);

    static std::string makeLowercase(std::string);
};

#endif // ZOORK_ZOORKENGINE_H
