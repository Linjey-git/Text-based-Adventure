//
// Created by serhi on 28.03.2023.
//

#ifndef STORY_GAME_ENTITY_H
#define STORY_GAME_ENTITY_H


#include "../GameObject.h"
#include "../item/Item.h"

class Entity : public GameObject{
protected:
    int hp;
    int damage;
    int armour;
    Item *entity_item;

public:
    Entity(const string &name, int hp, int damage, int armour, Item *entityItem);

    void performWithObject(GameObject *gameObject) override;

    string getName() override;

    int getHp() const;

    void setHp(int hp);

    int getDamage() const;

    void setDamage(int damage);

    int getArmour() const;

    void setArmour(int armour);

    Item *getEntityItem() const;

    void setEntityItem(Item *entityItem);

    bool empty();

    void display_entity();
};


#endif //STORY_GAME_ENTITY_H
