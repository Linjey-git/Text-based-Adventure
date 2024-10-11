//
// Created by serhi on 28.03.2023.
//

#ifndef STORY_GAME_PAGE_H
#define STORY_GAME_PAGE_H


#include "GameObject.h"
#include "entity/Entity.h"
#include <vector>

struct Option {
    string description;
    char behavior;
    string nextPage;
};

class Page : public GameObject {
private:
    string description;
    vector<Option> options;
    Entity *page_entity;
public:
    Page(const string &name, const string &description, const vector<Option> &options, Entity *pageEntity);

    const string &getDescription() const;

    void setDescription(const string &description);

    const vector<Option> &getOptions() const;

    void setOptions(const vector<Option> &options);

    Entity *getPageEntity() const;

    void setPageEntity(Entity *pageEntity);

    void performWithObject(GameObject *gameObject) override;

    string getName() override;
};


#endif //STORY_GAME_PAGE_H
