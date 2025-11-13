#ifndef ARBOR_SRC_CHARACTER_H
#define ARBOR_SRC_CHARACTER_H


class Room;

//data container to store data about the player character
//could probably be made into a struct, might be performance benefits?
class Character{
private:
    Room* current_room;
public:
    Room* get_current_room() {return current_room;}
    void set_current_room(Room* next_room) { current_room = next_room;}
};


#endif

