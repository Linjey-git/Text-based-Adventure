//
// Created by serhi on 28.03.2023.
//

#ifndef STORY_GAME_BAUBLE_H
#define STORY_GAME_BAUBLE_H


#include "Item.h"

class Bauble : public Item {
public:
    Bauble(string name, int plus);

    void performWithObject(GameObject *object) override;

    void set_basic_stats(GameObject *gameObject) override;
};


#endif //STORY_GAME_BAUBLE_H
