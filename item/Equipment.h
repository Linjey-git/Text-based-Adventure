//
// Created by serhi on 28.03.2023.
//

#ifndef STORY_GAME_EQUIPMENT_H
#define STORY_GAME_EQUIPMENT_H


#include "Item.h"

class Equipment : public Item {
public:
    void performWithObject(GameObject *object) override;

    Equipment(string name, int plus);

    void set_basic_stats(GameObject *gameObject) override;
};


#endif //STORY_GAME_EQUIPMENT_H
