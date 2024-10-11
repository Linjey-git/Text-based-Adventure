//
// Created by serhi on 27.03.2023.
//

#ifndef STORY_GAME_ITEM_H
#define STORY_GAME_ITEM_H


#include "../GameObject.h"

class Item : public GameObject {
private:
    string type;

protected:
    int plus;
public:



    Item(string name, int plus, string type);

    const string &getType() const;

    void setType(const string &type);

    int getPlus() const;

    void setPlus(int plus);

    void performWithObject(GameObject *gameObject) override;

    void display_item();

    virtual void set_basic_stats(GameObject *gameObject);
};


#endif //STORY_GAME_ITEM_H
