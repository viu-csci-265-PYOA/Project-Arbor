#include "../include/rayGameManager.h"

#include <raylib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// Get the current room object
bool RoomManager::loadRooms(const std::string& filename) {

    std::ifstream file(filename);

    if (!file.is_open()) return false;

    std::string line;
    while (std::getline(file, line)) {
    
        std::stringstream ss(line);
        Room r;
        std::string descPath;
        ss >> r.index >> r.name >> descPath >> r.option1 >> r.option2;
        
        // Load rooms description from file
        std::ifstream descFile(descPath);
        r.description.clear();
            if (descFile.is_open()) {
                std::string textline;
                while (std::getline(descFile, textline)) {
                    r.description += textline + "\n";
                }
            }

            rooms.push_back(r);
        }
    return true;
}



// Get a pointer to a room by index
const Room* RoomManager::getRoom(int index) const {
    for (const Room& r : rooms) {
        if (r.index == index) return &r;
    }
    return nullptr;
}



// Get the texture for a room by index
Texture2D RoomManager::getRoomTexture(int index) const {
    for (size_t i = 0; i < rooms.size(); i++) {
        if (rooms[i].index == index) return textures[i];
    }
    return {};
}



// Destructor to unload textures
RoomManager::~RoomManager() {

    for (const Texture2D& tex : textures) {
        UnloadTexture(tex);
    }
}
