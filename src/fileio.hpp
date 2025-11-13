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
    std::string _options;
  public:
    RoomInfo(int no, std::string name, std::string desc, std::string options): 
      _no(no),
      _name(name),
      _desc(desc),
      _options(options) {
    }

    ~RoomInfo(){}

    int get_room_no(){ return _no; }
    std::string get_room_name(){ return _name; }
    std::string get_desc_file(){ return _desc; }
    std::string get_options_file(){ return _options; }

    friend class Room;
};

//Builds vector of RoomInfo so that it can be indexed through to find files.
void get_directory(std::vector<RoomInfo>& dir);

//Retrieves description for a particular room from a narrative file.
std::string get_description(std::vector<RoomInfo>& dir, int choice);

//IN PROGRESS: Retrieves options for a particular room from a narrative file.
//std::string get_options(std::vector<RoomInfo>& dir, int choice);

#endif