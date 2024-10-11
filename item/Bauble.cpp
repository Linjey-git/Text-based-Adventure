//
// Created by serhi on 28.03.2023.
//

#include "Bauble.h"
#include "../entity/Player.h"

Bauble::Bauble(string name, int plus) : Item(name, plus, "bauble") {}


/*
 *
 * Adds to Player's hp its plus
 *
 * */
void Bauble::performWithObject(GameObject *object) {
    Player *player = dynamic_cast<Player *>(object);
    player->setHp(player->getHp() + Item::plus);
}

/*
 *
 * Set Player's hp to basic value by subtracting Item's plus.
 *
 * */
void Bauble::set_basic_stats(GameObject *gameObject) {
    Player *player = dynamic_cast<Player *>(gameObject);
    player->setHp(player->getHp() - this->getPlus());
}
