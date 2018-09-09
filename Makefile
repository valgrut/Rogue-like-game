SHELL=/bin/sh
CC=g++
FLAGS= -std=c++14 -Weffc++ -Wall -Wextra
COMMAND=$(CC) -c $<

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    FLAGS =-DDEBUG
else
    FLAGS=-DNDEBUG
endif

main: main.o Cell.o MapManager.o Map.o Player.o Game.o \
	Item.o iItemPointer.o Gold.o Weapon.o Armor.o Inventory.o \
	StateMachine.o iState.o State.o \
	StateStart.o StatePause.o StateInventory.o StateRunning.o StateEmpty.o StateStats.o
	$(CC) $(FLAGS) $^ -o $@

main.o: main.cpp
	$(COMMAND)

Cell.o: Cell.cpp Cell.h
	$(COMMAND)

MapManager.o: MapManager.cpp MapManager.h
	$(COMMAND)

Map.o: Map.cpp Map.h
	$(COMMAND)

Player.o: Player.cpp Player.h
	$(COMMAND)

Game.o: Game.cpp Game.h
	$(COMMAND)

Inventory.o: Inventory.cpp Inventory.h
	$(COMMAND)



#....................ITEMS............................................
iItemPointer.o: iItemPointer.cpp iItemPointer.h
	$(COMMAND)

Item.o: Item.cpp Item.h
	$(COMMAND)

Weapon.o: Weapon.cpp Weapon.h
	$(COMMAND)

Armor.o: Armor.cpp Armor.h
	$(COMMAND)

Sword.o: Sword.cpp Sword.h
	$(COMMAND)

Gold.o: Gold.cpp Gold.h
	$(COMMAND)



#....................STATES.............................................
iState.o: iState.cpp iState.h
	$(COMMAND)

StateMachine.o: StateMachine.cpp StateMachine.h #State.h #StateStart.h
	$(COMMAND)

State.o: State.cpp State.h iState.h #Game.h
	$(COMMAND)

StateStart.o: StateStart.cpp StateStart.h #State.h
	$(COMMAND)

StatePause.o: StatePause.cpp StatePause.h #State.h
	$(COMMAND)

StateInventory.o: StateInventory.cpp StateInventory.h #State.h
	$(COMMAND)

StateRunning.o: StateRunning.cpp StateRunning.h #State.h
	$(COMMAND)

StateStats.o: StateStats.cpp StateStats.h #State.h
	$(COMMAND)

StateEmpty.o: StateEmpty.cpp StateEmpty.h #State.h
	$(COMMAND)

clean:
	rm *.o
