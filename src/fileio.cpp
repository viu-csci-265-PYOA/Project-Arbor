#include "fileio.hpp"

void get_directory(std::vector<RoomInfo>& dir){
  std::ifstream input_read;
  input_read.open("resource/roomdir.txt");
  if(!input_read.is_open()){
    std::cout << "Unable to access room directory resource folder.\n";
    std::exit(-1);
  }
  
  int no;
  std::string name;
  std::string desc;
  std::string options;
  while(input_read >> no){
    input_read >> name >> desc >> options;
    dir.emplace_back(RoomInfo(no, name, desc, options));
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