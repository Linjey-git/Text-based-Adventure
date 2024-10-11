//
// Created by serhi on 28.03.2023.
//

#include "Weapon.h"
#include "../entity/Player.h"

Weapon::Weapon(string name, int plus) : Item(name, plus, "weapon") {}

/*
 *
 * Adds to Player's damage its plus
 *
 * */
void Weapon::performWithObject(GameObject *object) {
    Player *player = dynamic_cast<Player *>(object);
    player->setDamage(player->getDamage() + Item::plus);
}

/*
 *
 * Set Player's damage to basic value by subtracting Item's plus.
 *
 * */
void Weapon::set_basic_stats(GameObject *gameObject) {
    Player *player = dynamic_cast<Player *>(gameObject);
    player->setDamage(player->getDamage() - this->getPlus());
}
