//
// Created by serhi on 28.03.2023.
//
#include <vector>

#ifndef STORY_GAME_PLAYER_H
#define STORY_GAME_PLAYER_H


#include "Entity.h"

class Player : public Entity {
private:
    vector<Item *> inventory;

public:
    Player(const string &name, int hp, int damage, int armour);

    const vector<Item *> &getInventory() const;

    void setInventory(const vector<Item *> &inventory);

    void performWithObject(GameObject *gameObject) override;

    string getName() override;

    void addToInventory(Item *item);

    void save_game(string page_name);

    void display_inventory();

    void display_player();

    bool has_item(string type);

    void setName(string name);


};


#endif //STORY_GAME_PLAYER_H
