//
// Created by serhi on 27.03.2023.
//

#include "Item.h"
#include <iostream>

Item::Item(string name, int plus, string type) : GameObject(name), plus(plus), type(type) {}


/*
 *
 * Returns Item's type
 *
 * */
const string &Item::getType() const {
    return type;
}

/*
 *
 * Sets Item's type
 *
 * */
void Item::setType(const string &type) {
    Item::type = type;
}


/*
 *
 * Returns Item's plus
 *
 * */
int Item::getPlus() const {
    return plus;
}


/*
 *
 * Sets Item's plus
 *
 * */
void Item::setPlus(int plus) {
    Item::plus = plus;
}

/*
 *
 * Displays Item's stats
 *
 * */
void Item::display_item() {
    cout << "Item's stats:"
    << "\nname: " << this->name
    << "\nplus: " << this->plus
    << "\ntype: " << this->type << endl;
}

void Item::set_basic_stats(GameObject *gameObject) {
    return;
}

void Item::performWithObject(GameObject *gameObject) {
    return;
}