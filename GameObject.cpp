//
// Created by serhi on 27.03.2023.
//
#include <string>
#include "GameObject.h"

using namespace std;

GameObject::GameObject(string name) {
    this->name = name;
}

/*
 *
 * Returns the name of GameObject object
 *
 * */
string GameObject::getName() {
    return name;
}

