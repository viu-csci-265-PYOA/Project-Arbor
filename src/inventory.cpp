#include "inventory.hpp"

void Inventory::add_item(Item* new_item) {
    items.emplace_back(new_item);
}

int Inventory::name_search(std::string target_name) {
    for(int i = 0; i < items.size(); i++) {
        if(items[i]->get_name() == target_name) {
            return i;
        }
    }
    //in the case no match is found;
    return -1;
}

int Inventory::search(Item* target_item) {
    for(int i = 0; i < items.size(); i++) {
        if(items[i] == target_item) {
            return i;
        }
    }
    //in the case no match is found;
    return -1;
}
//overload for string
bool Inventory::check_has_item(std::string target_name) {
    int result = name_search(target_name);
    if(result != -1) {return true;} else {return false;}
}

//overload for item
bool Inventory::check_has_item(Item* target_item) {
    int result = search(target_item);
    if(result != -1) {return true;} else {return false;}
}

std::vector<std::string> Inventory::get_item_list() const {
    std::vector<std::string> item_list;
    for(int i = 0; i < items.size(); i++) {
        item_list[i] = items[i]->get_name();
    }
    return item_list;
}