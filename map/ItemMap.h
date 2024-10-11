//
// Created by serhi on 27.03.2023.
//

#ifndef STORY_GAME_ITEMMAP_H
#define STORY_GAME_ITEMMAP_H


#include "SerializedMap.h"
#include "../item/Item.h"

class ItemMap : public SerializedMap {
private:
    map<string, Item *> items;

    // to create objects
    struct Fields {
        string temp_name;
        int temp_plus;
        string temp_type;

        Fields() {
            clearFields();
        }

        void clearFields() {
            temp_name = "";
            temp_plus = 0;
            temp_type = "";
        }
    } fields;

public:
    ItemMap();

    const map<string, Item *> &getItems() const;

    void setItems(const map<string, Item *> &items);

    Item *getItem(string key);

    int getSize();

    void displayDebug(string name) override;

    void addItem(Item *item);

protected:
    void parse(const char type, string line) override;

    void addObj() override;
};


#endif //STORY_GAME_ITEMMAP_H
