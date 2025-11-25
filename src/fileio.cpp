#include "../include/fileio.hpp"

void get_directory(std::vector<RoomInfo>& dir){
  std::ifstream input_read;
  input_read.open("resource/narrative/room_dir.txt");
  if(!input_read.is_open()){
    std::cout << "Unable to access room directory resource folder.\n";
    std::exit(-1);
  }
  
  int no;
  std::string name;
  std::string desc;
  int option1;
  int option2;
  while(input_read >> no){
    input_read >> name >> desc >> option1 >> option2;
    dir.emplace_back(RoomInfo(no, name, desc, option1, option2));
  }

  input_read.close();
}

std::string get_description(RoomInfo room){
  std::string desc_file = room.get_desc_file();
  std::ifstream fetch_desc(desc_file);
  if(!fetch_desc.is_open()){
    std::cout << "Unable to access room description resource folder.\n";
    std::exit(-1);
  }
  
  std::string desc;
  std::getline(fetch_desc, desc, (char)std::char_traits<char>::eof());
  fetch_desc.close();

  return desc;
}

Room* create_room(std::vector<RoomInfo>& dir, int room_no){
  int index = search_directory(dir, room_no);
  if(index == -1){
    std::cout << "Unable to create room, invalid index.\n";
    return nullptr;
  }
  
  Room* new_room = new Room(
    room_no, dir[index].get_room_name(), 
    get_description(dir[index]), 
    dir[index].get_options1(), 
    dir[index].get_options2());
  
  return new_room;
}

Action* create_action(Room* room, Character* player){
  Command* new_command = new LeaveCommand(room, player);
  Action* new_action = new Action(room->get_name(), new_command);

  return new_action;
}

int search_directory(std::vector<RoomInfo>& dir, int room_no){
  int min = 0;
  int max = dir.size();
  int mid{}; 
  while(min <= max){
    mid = (min + max)/2;
    if(dir[mid].get_room_no() == room_no){
      return mid;
    }else if(dir[mid].get_room_no() > room_no){
      max = mid - 1;
    }else{
      min = mid + 1;
    }
  }

  std::cout << "Room does not exist in directory.\n";
  
  return -1;
}

Room* search_directory(std::vector<Room*>& game_rooms, int room_no){
  int min = 0;
  int max = game_rooms.size();
  int mid{}; 
  while(min <= max){
    mid = (min + max)/2;
    if(game_rooms[mid]->get_id() == room_no){
      return game_rooms[mid];
    }else if(game_rooms[mid]->get_id() > room_no){
      max = mid - 1;
    }else{
      min = mid + 1;
    }
  }

  std::cout << "Room does not exist in directory.\n";
  
  return nullptr;
}