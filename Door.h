//
// Created by FaZe-ltv on 5/21/2024.
//

#ifndef DOOR_H
#define DOOR_H
#include "Passage.h"

class Door : public Passage
{
public:
    Door(const std::string&, const std::string&, Room*, Room*, bool);

    Door(const std::string&, const std::string&, std::shared_ptr<Command>, Room*, Room*, bool);

    bool isLocked() const;

    void unlock();

    void lock();

protected:
    bool locked;
};

#endif //DOOR_H
