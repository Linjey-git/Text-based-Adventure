//
// Created by serhi on 28.03.2023.
//

#ifndef STORY_GAME_PAGEMAP_H
#define STORY_GAME_PAGEMAP_H


#include "SerializedMap.h"
#include "../Page.h"
#include "EntityMap.h"
#include "Player.h"

class PageMap : public SerializedMap {
private:
    map<string, Page *> pages;

    EntityMap *entityMap = new EntityMap();

    struct Fields {
        string temp_key;
        vector<Option> temp_options;
        string temp_description;
        string temp_entity_name;

        Fields() {
            clearFields();
        }

        void clearFields() {
            temp_key = "";
            temp_options.clear();
            temp_description = "";
            temp_entity_name = "";
        }
    } fields;

public:
    PageMap();

    void addPage(Page *page);

    int getSize();

    Page *getPage(string key);

    void displayDebug(string name) override;

    void display_page(string key);

    string next_page(Page * page, char choice, Player *player, int (*mainFunc)());

    string load_game(Player* player);

protected:
    void parse(const char type, string line) override;

    void addObj() override;
};


#endif //STORY_GAME_PAGEMAP_H
