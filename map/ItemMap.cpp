//
// Created by serhi on 27.03.2023.
//

#include "ItemMap.h"
#include "../item/Weapon.h"
#include "../item/Bauble.h"
#include "../item/Equipment.h"


/*
 *
 * Adds Item to ItemMap
 *
 * */
void ItemMap::addItem(Item *item) {
    items.insert(make_pair(item->getName(), item));
}

/*
 *
 * Returns ItemMap
 *
 * */
const map<string, Item *> &ItemMap::getItems() const {
    return items;
}


/*
 *
 * Sets ItemMap
 *
 * */
void ItemMap::setItems(const map<string, Item *> &items) {
    ItemMap::items = items;
}


/*
 *
 * Returns Item from ItemMap by key
 *
 * */
Item *ItemMap::getItem(string key) {
    try {
        return items[key];
    } catch (out_of_range) {
        cout << "Wrong key!\nCheck key's spelling!\n";
    }
    return nullptr;
}

/*
 *
 * Displays debug info about Item by key
 *
 * */
void ItemMap::displayDebug(string name) {

    Item *item = getItem(name);

    cout << "key: " << item->getName()
         << "\nplus: " << to_string(item->getPlus())
         << "\ntype: " << item->getType();
}


/*
 *
 * Parses data from file to right standard of Item object
 *
 * */
void ItemMap::parse(const char type, string line) {
    switch (type) {
        case 'n': {
            fields.temp_name = line;
            break;
        }
        case 'p': {
            fields.temp_plus = stoi(line);
            break;
        }
        case 't': {
            fields.temp_type = line;
            break;
        }
    }
}


/*
 *
 * Right adding a new just read Item object to map
 *
 * */
void ItemMap::addObj() {
    if (fields.temp_type == "weapon") {
        addItem(new Weapon(fields.temp_name, fields.temp_plus));
    } else if (fields.temp_type == "bauble") {
        addItem(new Bauble(fields.temp_name, fields.temp_plus));
    } else if (fields.temp_type == "equipment") {
        addItem(new Equipment(fields.temp_name, fields.temp_plus));
    }
    fields.clearFields();
}


/*
 *
 * Returns ItemMap's size
 *
 * */
int ItemMap::getSize() {
    return items.size();
}

ItemMap::ItemMap() {
    this->read_file("../data/items.dat");
}

