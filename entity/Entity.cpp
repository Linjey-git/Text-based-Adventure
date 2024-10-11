//
// Created by serhi on 28.03.2023.
//

#include "Entity.h"
#include "Player.h"
#include <iostream>

Entity::Entity(const string &name, int hp, int damage, int armour, Item *entityItem) : GameObject(name), hp(hp),
                                                                                       damage(damage), armour(armour),
                                                                                       entity_item(entityItem) {}


/*
 *
 * Make Entity give an Item to player
 *
 * */
void Entity::performWithObject(GameObject *gameObject) {
    Player *player = dynamic_cast<Player *>(gameObject);
    player->addToInventory(this->entity_item);
}


/*
 *
 * Returns PLayer's name
 *
 * */
string Entity::getName() {
    return GameObject::getName();
}

/*
 *
 * Returns PLayer's hp
 *
 * */
int Entity::getHp() const {
    return hp;
}


/*
 *
 * Sets Player's hp
 *
 * */
void Entity::setHp(int hp) {
    Entity::hp = hp;
}


/*
 *
 * Returns PLayer's damage
 *
 * */
int Entity::getDamage() const {
    return damage;
}

/*
 *
 * Sets Player's damage
 *
 * */
void Entity::setDamage(int damage) {
    Entity::damage = damage;
}


/*
 *
 * Returns PLayer's damage
 *
 * */
int Entity::getArmour() const {
    return armour;
}


/*
 *
 * Sets Player's armour
 *
 * */
void Entity::setArmour(int armour) {
    Entity::armour = armour;
}


/*
 *
 * Returns an Item that Entity collect
 *
 * */
Item *Entity::getEntityItem() const {
    return entity_item;
}


/*
 *
 * Sets an Item that Entity collect
 *
 * */
void Entity::setEntityItem(Item *entityItem) {
    entity_item = entityItem;
}


/*
 *
 * Checks if Entity's Item is null
 *
 * */
bool Entity::empty() {
    bool is_empty = true;
    if (this->name == "none" || this->name == "null") {
        is_empty = true;
    } else {
        is_empty = false;
    }
    return is_empty;
}


/*
 *
 * Displays Entity's stats
 *
 * */
void Entity::display_entity() {
    cout << "Entity's stats:"
         << "\nname: " << this->getName()
         << "\nhp: " << this->getHp()
         << "\ndamage: " << this->getDamage()
         << "\narmour: " << this->getArmour() << endl;
}

