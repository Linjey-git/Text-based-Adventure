//
// Created by serhi on 28.03.2023.
//

#include <fstream>
#include <iostream>
#include "Player.h"

string get_inventory_string(vector<Item *> inventory);

Player::Player(const string &name, int hp, int damage, int armour)
        : Entity(name, hp, damage, armour, nullptr) {}


/*
 *
 * Returns Player's inventory
 *
 * */
const vector<Item *> &Player::getInventory() const {
    return inventory;
}

/*
 *
 * Set Player's inventory
 *
 * */
void Player::setInventory(const vector<Item *> &inventory) {
    Player::inventory = inventory;
}


/*
 *
 * Make Player fight with Entity
 *
 * */
void Player::performWithObject(GameObject *gameObject) {
    Entity *entity = dynamic_cast<Entity *>(gameObject);
    int hp = this->getHp();
    while (true) {
        this->setHp((this->getHp() + this->getArmour() * .75) - entity->getDamage());
        entity->setHp((entity->getHp() + entity->getArmour() * 0.75) - this->getDamage());
        if (entity->getHp() <= 0) {
            this->setHp(hp);
            break;
        }
        if (this->getHp() <= 0) {
            break;
        }
    }
}


/*
 *
 * Returns Player's name
 *
 * */
string Player::getName() {
    return Entity::getName();
}

/*
 *
 * Checks the Player's inventory for a personal type item and replaces it
 *
 * */
void Player::addToInventory(Item *item) {
    for (int i = 0; i < this->inventory.size(); ++i) {
        if (this->inventory[i]->getType() == item->getType()) {
            this->inventory.erase(this->inventory.begin() + i);
            break;
        }
    }
    this->inventory.push_back(item);
}


/*
 *
 * Saves game
 *
 * */
void Player::save_game(string page_name) {
    string current_page_name = page_name;
    string current_player_name = this->getName();
    int current_hp = this->getHp();
    int current_armour = this->getArmour();
    int current_damage = this->getDamage();
    string current_inventory = get_inventory_string(inventory);

    fstream writeFile;

    writeFile.open("../data/saves.dat");

    if (writeFile.is_open()) {
        //cout << "File is found!\n\n";
        writeFile << "p:" << current_page_name
                  << "\nn:" << current_player_name
                  << "\nh:" << current_hp
                  << "\na:" << current_armour
                  << "\nd:" << current_damage
                  << "\ni:" << current_inventory
                  << "\nend\n";
        writeFile.close();
        cout << "\nSaved\n\n";
    } else {
        cout << "File cannot be opened!\n\n";
    }
}


/*
 *
 * Displays Player's inventory
 *
 * */
void Player::display_inventory() {
    cout << "\nInventory: ";
    for (int i = 0; i < inventory.size(); ++i) {
        cout << inventory[i]->getName() << "; ";
    }
    cout << endl;
}


/*
 *
 * Displays Player's stats
 *
 * */
void Player::display_player() {
    cout << "\nPlayer's stats:"
         << "\nname: " << this->getName()
         << "\nhp: " << this->getHp()
         << "\ndamage: " << this->getDamage()
         << "\narmour: " << this->getArmour() << endl;
    display_inventory();
}


/*
 *
 * Returns Player's inventory as a string with delimiters
 *
 * */
string get_inventory_string(vector<Item *> inventory) {
    string current_inventory = "";
    for (int i = 0; i < inventory.size(); ++i) {
        current_inventory += inventory[i]->getName() + "|";
    }
    if (current_inventory != "") {
        current_inventory.erase(current_inventory.size() - 1);
    }
    return current_inventory;
}


/*
 *
 * Returns true if in Player has item with specific type. If do not have it - returns false
 *
 * */
bool Player::has_item(std::string type) {
    bool has_item = false;
    for (int i = 0; i < inventory.size(); ++i) {
        if (inventory[i]->getType() == type) {
            has_item = true;
            break;
        }
    }
    return has_item;
}


/*
 *
 * Set Player's name
 *
 * */
void Player::setName(std::string name) {
    this->name = name;
}