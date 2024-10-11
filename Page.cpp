//
// Created by serhi on 28.03.2023.
//

#include "Page.h"

Page::Page(const string &name, const string &description, const vector<Option> &options, Entity *pageEntity)
        : GameObject(name), description(description), options(options), page_entity(pageEntity) {}

/*
 *
 * Returns Page's description
 *
 * */
const string &Page::getDescription() const {
    return description;
}

/*
 *
 * Sets Page's description
 *
 * */
void Page::setDescription(const string &description) {
    Page::description = description;
}

/*
 *
 * Returns a vector of Option that Page contains inside
 *
 * */
const vector<Option> &Page::getOptions() const {
    return options;
}

/*
 *
 * Sets a vector of Option that Page contains inside
 *
 * */
void Page::setOptions(const vector<Option> &options) {
    Page::options = options;
}


/*
 *
 * Returns a Page's Entity
 *
 * */
Entity *Page::getPageEntity() const {
    return page_entity;
}

/*
 *
 * Sets a Page's Entity
 *
 * */
void Page::setPageEntity(Entity *pageEntity) {
    page_entity = pageEntity;
}

void Page::performWithObject(GameObject *gameObject) {
    return;
}


/*
 *
 * Returns Page's name
 *
 * */
string Page::getName() {
    return GameObject::getName();
}
