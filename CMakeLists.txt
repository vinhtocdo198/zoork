cmake_minimum_required(VERSION 3.23)
project(ZOOrk)

set(CMAKE_CXX_STANDARD 20)

add_executable(ZOOrk main.cpp Item.h Command.h Item.cpp Character.cpp Character.h Location.cpp Location.h GameObject.cpp GameObject.h Room.cpp Room.h Passage.cpp Passage.h NullRoom.cpp NullRoom.h NullCommand.cpp NullCommand.h Player.cpp Player.h RoomDefaultEnterCommand.cpp RoomDefaultEnterCommand.h ZOOrkEngine.cpp ZOOrkEngine.h PassageDefaultEnterCommand.cpp PassageDefaultEnterCommand.h NullPassage.cpp NullPassage.h
        SweepLeavesCommand.h
        SweepLeavesCommand.cpp
        Door.h
        Door.cpp
        UnlockDoorCommand.h
        UnlockDoorCommand.cpp
        SetFireCommand.h
        SetFireCommand.cpp
        LightUpCommand.h
        LightUpCommand.cpp
        PlayPianoCommand.cpp
        PlayPianoCommand.h
        ClearWaterCommand.cpp
        ClearWaterCommand.h
        InstallClockHandCommand.cpp
        InstallClockHandCommand.h
        RemoveStitchesCommand.cpp
        RemoveStitchesCommand.h
        LieDownCommand.cpp
        LieDownCommand.h
        UnlockChestCommand.cpp
        UnlockChestCommand.h
        OpenDrawerCommand.cpp
        OpenDrawerCommand.h
        InsertLetterCommand.cpp
        InsertLetterCommand.h
        Bookshelf.cpp
        Bookshelf.h
        RearrangeBookCommand.cpp
        RearrangeBookCommand.h
        WearRingCommand.cpp
        WearRingCommand.h
        EscapeCommand.cpp
        EscapeCommand.h)
