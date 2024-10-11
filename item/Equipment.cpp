//
// Created by serhi on 28.03.2023.
//

#include "Equipment.h"
#include "../entity/Player.h"

Equipment::Equipment(string name, int plus) : Item(name, plus, "equipment") {}

/*
 *
 * Adds to Player's armour its plus
 *
 * */
void Equipment::performWithObject(GameObject *object) {
    Player *player = dynamic_cast<Player *>(object);
    player->setArmour(player->getArmour() + Item::plus);
}

/*
 *
 * Set Player's armour to basic value by subtracting Item's plus.
 *
 * */
void Equipment::set_basic_stats(GameObject *gameObject) {
    Player *player = dynamic_cast<Player *>(gameObject);
    player->setArmour(player->getArmour() - this->getPlus());
}
