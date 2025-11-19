#ifndef ARBOR_SRC_ITEM_H
#define ARBOR_SRC_ITEM_H

#include <iostream>
#include <vector>

class Item {
private:
    std::string name;
    std::string desc;
public:
    Item(std::string item_name, std::string item_desc) 
        : name(item_name), desc(item_desc) {}

    std::string get_name() const {return name;}
    std::string get_desc() const {return desc;}

    void set_name(std::string item_name) {name = item_name;}
    void set_desc(std::string item_desc) {desc = item_desc;}

};

//vector of items to be associated with a Character.
class Inventory {
private:
    std::vector<Item*> items;

    int name_search(std::string target_name);
    int search(Item* target_item);
public:
    Inventory() {}
    Inventory(Item* first_item) {items.emplace_back(first_item);}

    ~Inventory() {}

    int get_inventory_count() const {return items.size();}
    std::vector<std::string> get_item_list() const;

    void add_item(Item* new_item);

    bool check_has_item(std::string target_name);
    bool check_has_item(Item* target_item);
};

#endif