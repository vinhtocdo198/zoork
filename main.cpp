#include "Passage.h"
#include "Room.h"
#include "ZOOrkEngine.h"
#include <memory>

#include "Bookshelf.h"
#include "ClearWaterCommand.h"
#include "Door.h"
#include "InsertLetterCommand.h"
#include "InstallClockHandCommand.h"
#include "LieDownCommand.h"
#include "LightUpCommand.h"
#include "OpenDrawerCommand.h"
#include "PlayPianoCommand.h"
#include "RearrangeBookCommand.h"
#include "RemoveStitchesCommand.h"
#include "SweepLeavesCommand.h"
#include "UnlockDoorCommand.h"
#include "SetFireCommand.h"

int main()
{
    std::cout << "Welcome to the haunted manor! You are in debt and desperately in need of money.\n"
        "Lucky for you, there is an ancient jewelry hidden within this eerie, abandoned house.\n"
        "This is your chance to change your life, but the thought of venturing inside sends\n"
        "chills down your spine. Do you dare to take this challenge?\n"
        "Type help/h for available commands.\n\n";

    // Front yard
    const auto front_yard = std::make_shared<Room>("front-yard",
                                                   "You are standing in a lawn south of the manor, under the heavy rain. All windows\n"
                                                   "are barred. There is a rusty lock on the front door, and a [broom] lying on the\n"
                                                   "floor. A [leaf-pile] is on your left, in front of the windows.\n");
    const auto front_key = std::make_shared<Item>("front-key", "A cute key.", true, false);
    const auto lighter = std::make_shared<Item>("lighter", "A lighter, small and convenient.", true, false);
    const auto leaf_pile = std::make_shared<Item>("leaf-pile", "A very normal pile of leaves.", false, false);
    const auto broom = std::make_shared<Item>("broom", "An old broom.", true, false);
    front_yard->addItem(leaf_pile.get());
    front_yard->addItem(broom.get());
    front_yard->addItem(front_key.get());
    front_yard->addItem(lighter.get());

    const auto foyer = std::make_shared<Room>("foyer",
                                              "You are now in the foyer of the house. It's so dark that you can't see a thing,\n"
                                              "except an [oil-lamp] on the window frame on your right.\n");
    const auto front_door = std::make_shared<Door>("front-door", "This door looks sturdy.", front_yard.get(),
                                                   foyer.get(), true);

    // Interactions
    const auto unlock_front_door_command = std::make_shared<UnlockDoorCommand>(front_door.get());
    const auto sweep_leaves_command = std::make_shared<SweepLeavesCommand>(front_yard.get());
    broom->setUseCommand(sweep_leaves_command);
    front_key->setUseCommand(unlock_front_door_command);

    const auto living_room = std::make_shared<Room>("living-room",
                                                    "You are now in the living room. A corridor leads to the kitchen to the north.\n"
                                                    "A worn-out [sofa] is in the middle, facing a vintage [TV]. Above the TV, a [clock]\n"
                                                    "and a Mona Lisa [painting] are hung on the wall.\n");
    const auto sofa = std::make_shared<Item>("sofa", "An old, worn-out sofa.", false, true);
    const auto tv = std::make_shared<Item>("tv", "A vintage TV.", false, true);
    const auto clock = std::make_shared<Item>("clock", "A cuckoo clock mounted on the wall, missing a hand.", false,
                                              false);
    const auto painting = std::make_shared<Item>("painting", "A replica of the Mona Lisa painting.", false, false);
    const auto hole = std::make_shared<Item>("hole",
                                             "A small hole in the wall, and the sun inside?... No it's a sparky [ring].",
                                             false, false);
    const auto ring = std::make_shared<Item>("ring",
                                             "A charming, flawless, intricate, exotic, gorgeous, sexy,... ring. This is it!",
                                             true, false);
    living_room->addItem(sofa.get());
    living_room->addItem(tv.get());
    living_room->addItem(clock.get());
    living_room->addItem(painting.get());
    living_room->addItem(hole.get());
    living_room->addItem(ring.get());
    const auto lie_down_command = std::make_shared<LieDownCommand>(sofa.get());
    sofa->setUseCommand(lie_down_command);

    const auto hallway = std::make_shared<Room>("hallway",
                                                "You are now in the hallway. A huge [piano] appears before your eyes.\n"
                                                "Ahead is a door standing slightly ajar. There is another door on your\n"
                                                "left and one more on your right.\n");
    const auto piano = std::make_shared<Item>("piano", "A grand piano, in good condition. Should I play it?", false,
                                              true);
    hallway->addItem(piano.get());
    const auto play_piano_command = std::make_shared<PlayPianoCommand>(piano.get());
    piano->setUseCommand(play_piano_command);

    const auto oil_lamp = std::make_shared<Item>("oil-lamp", "An old-fashioned oil lamp. Must be a hundred years old.",
                                                 false, false);
    foyer->addItem(oil_lamp.get());
    const auto set_fire_command = std::make_shared<SetFireCommand>(lighter.get(), oil_lamp.get());
    lighter->setUseCommand(set_fire_command);

    const auto light_up_command = std::make_shared<LightUpCommand>(oil_lamp.get(), foyer.get(),
                                                                   living_room.get(), hallway.get());
    oil_lamp->setUseCommand(light_up_command);

    const auto kitchen = std::make_shared<Room>("kitchen",
                                                "You are now in the kitchen. It is a total mess, with a [dining-table] covered in\n"
                                                "plates of rotten food. A [fridge] stands in the corner next to a [stove], both coated\n"
                                                "in dust and cobwebs. The air is thick with a sense of decay.\n");
    const auto dining_table = std::make_shared<Item>("dining-table",
                                                     "A dining table, but I wouldn't sit here to enjoy my meals.",
                                                     false, false);
    const auto fridge = std::make_shared<Item>("fridge", "A grimy fridge, with a [note] clinging to the door.",
                                               false, false);
    const auto note = std::make_shared<Item>("note",
                                             "A sticky note, edges curling with age. There is ugly handwriting on it:\n"
                                             "Bla bla bla", true, false); // TODO:
    const auto stove = std::make_shared<Item>("stove", "An old stove.", false, false);
    kitchen->addItem(dining_table.get());
    kitchen->addItem(fridge.get());
    kitchen->addItem(note.get());
    kitchen->addItem(stove.get());

    const auto laundry_room = std::make_shared<Room>("laundry-room",
                                                     "You are now in the laundry room. There's nothing other than a [sink] and a\n"
                                                     "[washing-machine].\n");
    const auto sink = std::make_shared<Item>("sink", "A flooded sink with water spilling over the edges.", false, true);
    const auto washing_machine = std::make_shared<Item>("washing-machine", "A broken washing machine.", false, false);
    const auto knife = std::make_shared<Item>("knife", "A sharp knife, might come in handy.", true, false);
    laundry_room->addItem(sink.get());
    laundry_room->addItem(washing_machine.get());
    laundry_room->addItem(knife.get());
    const auto remove_stitches_command = std::make_shared<RemoveStitchesCommand>(knife.get());
    knife->setUseCommand(remove_stitches_command);
    const auto clear_water_command = std::make_shared<ClearWaterCommand>(laundry_room.get());
    sink->setUseCommand(clear_water_command);

    const auto toilet_room = std::make_shared<Room>("toilet-room",
                                                    "You are now in the toilet. A small, cramped room with just a basic [toilet].\n");
    const auto toilet = std::make_shared<Item>("toilet", "Just a toilet, nothing else to see here.", false, false);
    toilet_room->addItem(toilet.get());

    // 2nd floor
    const auto master_bedroom = std::make_shared<Room>("master-bedroom",
                                                       "You are now in the master bedroom. A spacious room, dominated by a huge [bed]\n"
                                                       "in the middle. Next to it is a desk, and on top of it lies an old [chest].\n"
                                                       "A pathway north leads to the balcony.\n");
    const auto bed = std::make_shared<Item>("bed", "A huge bed with an ornate headboard.", false, true);
    const auto chest = std::make_shared<Item>("chest", "A wooden chest, secured with a sturdy combination lock.", false,
                                              true);
    const auto e = std::make_shared<Item>("e", "A wooden piece of letter E.", true, false);
    const auto d = std::make_shared<Item>("d", "A wooden piece of letter D.", true, false);
    master_bedroom->addItem(bed.get());
    master_bedroom->addItem(chest.get());
    master_bedroom->addItem(e.get());
    master_bedroom->addItem(d.get());
    bed->setUseCommand(lie_down_command);
    const auto unlock_chest_command = std::make_shared<UnlockChestCommand>(chest.get());
    chest->setUseCommand(unlock_chest_command);

    const auto balcony = std::make_shared<Room>("balcony",
                                                "You are now on the balcony. The storm is still raging, better to get back inside.\n");

    const auto kid_bedroom = std::make_shared<Room>("kid-bedroom",
                                                    "You are now in the kid's bedroom. The room is almost empty and eerily silent.\n"
                                                    "There is a [bookshelf] on the left and a big [teddy-bear] sitting on the bed.\n");
    const auto bookshelf = std::make_shared<Bookshelf>("bookshelf",
                                                       "A bookshelf, filled with children's books. The top shelf stands out: it holds seven books,\n"
                                                       "with some of them displaying wooden letters on their spines. The others have their spines\n"
                                                       "curved inward, also in the shape of letters. Current letters on the books are:\n"
                                                       "3, s, p, c", false, false,
                                                       std::vector<std::string>{"3", "s", "p", "c"});
    const auto teddy_bear = std::make_shared<Item>("teddy-bear", "A stuffed teddy bear, body covered with stitches.",
                                                   false, false);
    const auto clock_hand = std::make_shared<Item>("clock-hand", "A clock's hand.", true, false);
    kid_bedroom->addItem(bookshelf.get());
    kid_bedroom->addItem(teddy_bear.get());
    kid_bedroom->addItem(clock_hand.get());
    const auto install_clock_hand_command = std::make_shared<InstallClockHandCommand>(clock.get());
    clock_hand->setUseCommand(install_clock_hand_command);

    const auto bathroom = std::make_shared<Room>("bathroom",
                                                 "You are now in the bathroom. A [drawer] is in the corner, barely visible\n"
                                                 "in the darkness. Below is a large [bathtub].\n");
    const auto drawer = std::make_shared<Item>("drawer", "A first aid drawer.", false, true);
    const auto bathtub = std::make_shared<Item>("bathtub", "A large bathtub, filled with green moss.", false, true);
    const auto s = std::make_shared<Item>("s", "A wooden piece of letter S.", true, false);
    bathroom->addItem(drawer.get());
    bathroom->addItem(bathtub.get());
    bathroom->addItem(s.get());
    const auto open_drawer_command = std::make_shared<OpenDrawerCommand>(drawer.get());
    drawer->setUseCommand(open_drawer_command);
    bathtub->setUseCommand(lie_down_command);

    const auto insert_letter_command1 = std::make_shared<InsertLetterCommand>(s.get());
    s->setUseCommand(insert_letter_command1);
    const auto insert_letter_command2 = std::make_shared<InsertLetterCommand>(e.get());
    e->setUseCommand(insert_letter_command2);
    const auto insert_letter_command3 = std::make_shared<InsertLetterCommand>(d.get());
    d->setUseCommand(insert_letter_command3);
    const auto rearrange_book_command = std::make_shared<RearrangeBookCommand>(bookshelf.get(), living_room.get());
    bookshelf->setUseCommand(rearrange_book_command);

    // TODO: what happens after getting the ring? front door opens and house is crumbling

    // 1st floor passages
    Passage::createBasicPassage(living_room.get(), kitchen.get(), "north", true);
    Passage::createBasicPassage(kitchen.get(), laundry_room.get(), "west", true);
    Passage::createBasicPassage(laundry_room.get(), toilet_room.get(), "south", true);

    // 2nd floor passages
    Passage::createBasicPassage(hallway.get(), master_bedroom.get(), "north", true);
    Passage::createBasicPassage(hallway.get(), kid_bedroom.get(), "west", true);
    Passage::createBasicPassage(hallway.get(), bathroom.get(), "east", true);
    Passage::createBasicPassage(master_bedroom.get(), balcony.get(), "north", true);

    ZOOrkEngine zoork(front_yard);

    zoork.run();

    return 0;
}
