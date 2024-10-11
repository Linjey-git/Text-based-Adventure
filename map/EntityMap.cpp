//
// Created by serhi on 28.03.2023.
//

#include "EntityMap.h"

/*
 *
 * Displays debug info about Entity by key
 *
 * */
void EntityMap::displayDebug(string name) {
    Entity *entity = getEntity(name);

    cout << "name: " << entity->getName()
         << "\nhp: " << to_string(entity->getHp())
         << "\ndamage: " << to_string(entity->getDamage())
         << "\narmour: " << to_string(entity->getArmour())
         << "\nitem name: " << entity->getEntityItem()->getName()
         << "\nItem info:\n" << entity->getEntityItem()->getPlus()
         << "\n" << entity->getEntityItem()->getType();
}


/*
 *
 * Parses data from file to right standard of Entity object
 *
 * */
void EntityMap::parse(const char type, string line) {
    switch (type) {
        case 'n': {
            fields.temp_name = line;
            break;
        }
        case 'h': {
            fields.temp_hp = stoi(line);
            break;
        }
        case 'd': {
            fields.temp_damage = stoi(line);
            break;
        }
        case 'a': {
            fields.temp_armour = stoi(line);
            break;
        }
        case 'i': {
            fields.temp_item_name = line;
            break;
        }
    }
}

/*
 *
 * Right adding a new just read Entity object to map
 *
 * */
void EntityMap::addObj() {
    if (itemMap == nullptr) {
        throw std::invalid_argument("Need fill pointer itemMap before use");
    }
    addEntity(new Entity(fields.temp_name,
                         fields.temp_hp,
                         fields.temp_damage,
                         fields.temp_armour,
            // need check for nullprt for itemMap
                         itemMap->getItem(fields.temp_item_name)));
}

/*
 *
 * Returns EntityMap's size
 *
 * */
int EntityMap::getSize() {
    return entities.size();
}

/*
 *
 * Adds Entity to EntityMap
 *
 * */
void EntityMap::addEntity(Entity *entity) {
    entities.insert(make_pair(entity->getName(), entity));
}

/*
 *
 * Returns Entity from EntityMap by key
 *
 * */
Entity *EntityMap::getEntity(string key) {
    try {
        return entities[key];
    } catch (out_of_range) {
        cout << "Wrong key!\nCheck key's spelling!\n";
    }
    return nullptr;
}

EntityMap::EntityMap() {
//    itemMap->read_file("../../items.dat");
    this->read_file("../data/entities.dat");
}

/*
 *
 * Returns an ItemMap map from EntityMap
 *
 * */
ItemMap* EntityMap::getItemMap() {
    return this->itemMap;
}