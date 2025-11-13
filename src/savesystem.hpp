#include <string>
#include <iostream>
#include <fstream>

namespace save_system {

    //template to save any object it's passed a pointer of
    //saves to a .bin file at the destination file path.
    template <typename T> void save_object(T* x, std::string file_name) {
        std::ofstream file(file_name, std::ios::binary);
        if (!file.is_open())
        {
            std::cout << "failed to open file to save object." << '\n';
            return;
        }
        //reinterpret_cast takes a pointer,
        // while sizeof should be passed the dereferenced object.
        file.write(reinterpret_cast<const char*>(x), sizeof(*x));
        file.close();
        std::cout << "object saved successfully." << '\n';
    }

    //loads an object of any type from the provided destination file path
    //returns a pointer to that object.
    template <typename T> T* load_object(std::string file_name){
        T* x = new T;
        std::ifstream file(file_name, std::ios::binary);
        if(!file.is_open()) {
            std::cout << "failed to open file to load object" << '\n';
            return x;
        }
        //reinterpret_cast takes a pointer,
        // while sizeof should be passed the dereferenced object.
        file.read(reinterpret_cast<char*>(x), sizeof(*x));
        file.close();
        std::cout << "object loaded successfully." << '\n';
        return x;
    }
}