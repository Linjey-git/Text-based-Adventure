//
// Created by serhi on 28.03.2023.
//

#ifndef STORY_GAME_ENTITYMAP_H
#define STORY_GAME_ENTITYMAP_H


#include "SerializedMap.h"
#include "../entity/Entity.h"
#include "ItemMap.h"

class EntityMap : public SerializedMap {
private:
    map<string, Entity *> entities;

    ItemMap *itemMap = new ItemMap();

    // create objects
    struct Fields {
        string temp_name;
        int temp_hp;
        int temp_damage;
        int temp_armour;
        string temp_item_name;

        Fields() {
            clearFields();
        }

        void clearFields() {
            temp_name = "";
            temp_hp = 0;
            temp_damage = 0;
            temp_armour = 0;
            temp_item_name = "";
        }
    } fields;

public:
    EntityMap();

    void addEntity(Entity *entity);

    int getSize();

    Entity *getEntity(string key);

    void displayDebug(string name) override;

    ItemMap* getItemMap();

protected:
    void parse(const char type, string line) override;

    void addObj() override;

};


#endif //STORY_GAME_ENTITYMAP_H
