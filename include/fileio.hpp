#ifndef ARBOR_SRC_FILEIO_H
#define ARBOR_SRC_FILEIO_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "room.hpp"

//RoomInfo classes stores the room number, name, and file names for each room
//in our room directory.
class RoomInfo{
  private:
    int _no;
    std::string _name;
    std::string _desc;
    int _option1;
    int _option2;
  public:
    RoomInfo(int no, std::string name, std::string desc, int opt1, int opt2): 
      _no(no),
      _name(name),
      _desc(desc),
      _option1(opt1),
      _option2(opt2) {
    }

    ~RoomInfo(){}

    int get_room_no(){ return _no; }
    std::string get_room_name(){ return _name; }
    std::string get_desc_file(){ return _desc; }
    int get_options1(){ return _option1; }
    int get_options2(){ return _option2; }

    
    friend class Room;
};

//Builds vector of RoomInfo so that it can be indexed through to find files.
void get_directory(std::vector<RoomInfo>& dir);

//Retrieves description for a particular room from a narrative file.
std::string get_description(RoomInfo room);

//Binary searches the directory for the specific room.
int search_directory(std::vector<RoomInfo>& dir, int room_no);

//Binary searches game rooms for a particular room.
Room* search_directory(std::vector<Room*>& game_rooms, int room_no);

//Creates a room given a room ID and returns the pointer to the room object.
Room* create_room(std::vector<RoomInfo>& dir, int room_no);

//Creates Action pointer for add_action to be used after directory, rooms,
//and character declaration
Action* create_action(Room* room, Character* player, GameState* state);



#endif