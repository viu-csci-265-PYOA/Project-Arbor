#include "../include/fileio.hpp"

void get_directory(std::vector<RoomInfo>& dir){
  std::ifstream input_read;
  input_read.open("resource/room_dir.txt");
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

std::string get_description(std::vector<RoomInfo>& dir, int choice){
  std::string desc_file = dir[choice].get_desc_file();
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

/*
std::string get_options(std::vector<RoomInfo>& dir, int choice){
  std::ifstream fetch_options(dir[choice].get_options_file());
  if(!fetch_options.is_open()){
    std::cout << "Unable to access room description resource folder.\n";
    std::exit(-1);
  }
  std::string options;
  std::getline(fetch_options, options, (char)std::char_traits<char>::eof());
  fetch_options.close();

  return options;
}*/

Room* create_room(std::vector<RoomInfo>& dir, int room_no){

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