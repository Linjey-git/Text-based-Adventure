//
// Created by serhi on 28.03.2023.
//

#ifndef STORY_GAME_WEAPON_H
#define STORY_GAME_WEAPON_H


#include "Item.h"

class Weapon : public Item {
public:
    void performWithObject(GameObject *object) override;

    Weapon(string name, int plus);

    void set_basic_stats(GameObject *gameObject) override;
};


#endif //STORY_GAME_WEAPON_H
