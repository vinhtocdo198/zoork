#include "Passage.h"
#include "Room.h"
#include "ZOOrkEngine.h"
#include <memory>

#include "Door.h"
#include "SweepLeavesCommand.h"
#include "UnlockDoorCommand.h"

int main()
{
    std::cout << "Welcome to the haunted manor! You are in debt and desperately in need of money.\n"
        "Lucky for you, there is ancient jewelry hidden within this eerie, abandoned house.\n"
        "This is your chance to change your life, but the thought of venturing inside sends\n"
        "chills down your spine. Do you dare to take this challenge?\n\n";

    // TODO: ask for obtainable items?

    // Front yard
    const auto front_yard = std::make_shared<Room>("front-yard",
                                                   "You are standing in a lawn south of the manor. All windows are barred.\n"
                                                   "There is a rusty lock on the front door, and a broom lying on the floor.\n"
                                                   "A leaf pile is on your left, in front of the windows.\n");
    const auto front_key = std::make_shared<Item>("front-key", "A small, rusty key.", true);
    const auto leaf_pile = std::make_shared<Item>("leaf-pile", "A very normal pile of leaves.", false);
    const auto broom = std::make_shared<Item>("broom", "An old broom.", true);
    front_yard->addItem(leaf_pile.get());
    front_yard->addItem(broom.get());
    front_yard->addItem(front_key.get());

    const auto foyer = std::make_shared<Room>("foyer",
                                              "You are now in the foyer of the house. There is a light switch on your right.\n");
    const auto front_door = std::make_shared<Door>("front-door", "This door looks sturdy.", front_yard.get(),
                                                   foyer.get(), true);

    // Interactions
    const auto unlock_front_door_command = std::make_shared<UnlockDoorCommand>(front_door.get());
    const auto sweep_leaves_command = std::make_shared<SweepLeavesCommand>(front_yard.get());
    broom->setUseCommand(sweep_leaves_command);
    front_key->setUseCommand(unlock_front_door_command);
    // TODO: Add a light switch item

    const auto living_room = std::make_shared<Room>("living-room",
                                                    "You are now in the living room. A corridor leads to the kitchen to the north.\n");

    const auto kitchen = std::make_shared<Room>("kitchen",
                                                "You are now in the kitchen. The laundry room is on the west.\n");

    const auto laundry_room = std::make_shared<Room>("laundry-room",
                                                     "You are now in the laundry room. The kitchen is on the east.\n");

    const auto toilet = std::make_shared<Room>("toilet",
                                               "You are now in the toilet. The bathroom is to the east.\n");

    const auto piano = std::make_shared<Room>("piano",
                                              "You are now in the piano room. The living room is to the south.\n");

    const auto master_bedroom = std::make_shared<Room>("master-bedroom",
                                                       "You are now in the master bedroom. The bathroom is to the east.\n");

    const auto ensuite_bathroom = std::make_shared<Room>("ensuite_bathroom",
                                                         "You are now in the ensuite. The master bedroom is to the west.\n");

    const auto balcony = std::make_shared<Room>("balcony",
                                                "You are now in the balcony. The bathroom is to the east.\n");

    const auto kid_bedroom = std::make_shared<Room>("kid-bedroom",
                                                    "You are now in the kid's bedroom. The bathroom is to the east.\n");

    const auto bathroom = std::make_shared<Room>("bathroom",
                                                 "You are now in the bathroom. The master bedroom is to the west.\n");

    // TODO: Add items to rooms, describe the rooms better

    Passage::createBasicPassage(foyer.get(), living_room.get(), "north", true);
    Passage::createBasicPassage(living_room.get(), kitchen.get(), "north", true);
    Passage::createBasicPassage(kitchen.get(), laundry_room.get(), "west", true);
    Passage::createBasicPassage(laundry_room.get(), toilet.get(), "south", true);

    // 2nd floor passages
    Passage::createBasicPassage(foyer.get(), piano.get(), "up", true);
    Passage::createBasicPassage(piano.get(), master_bedroom.get(), "north", true);
    Passage::createBasicPassage(master_bedroom.get(), ensuite_bathroom.get(), "east", true);
    Passage::createBasicPassage(master_bedroom.get(), balcony.get(), "north", true);
    Passage::createBasicPassage(piano.get(), kid_bedroom.get(), "west", true);
    Passage::createBasicPassage(piano.get(), bathroom.get(), "east", true);

    ZOOrkEngine zoork(front_yard);

    zoork.run();

    return 0;
}
