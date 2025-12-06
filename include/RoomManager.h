#pragma once
#include <vector>
#include <string>

// Room structure
// Represents a room
struct Room {
    int index;
    std::string name;
    std::string description;
    int option1;
    int option2;
};

// RoomManager class
// Manages loading and accessing rooms
// and their associated textures
class RoomManager {
private:
    std::vector<Room> rooms;
    std::vector<Texture2D> textures;

public:
    bool loadRooms(const std::string& filePath); // Load rooms from a file

    const Room* getRoom(int index) const; // Get room by index

    Texture2D getRoomTexture(int index) const; // Get texture for a room by index

    ~RoomManager(); // Destructor to unload textures
};