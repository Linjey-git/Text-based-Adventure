//
// Created by serhi on 27.03.2023.
//

#include <string>


#ifndef STORY_GAME_GAMEOBJECT_H
#define STORY_GAME_GAMEOBJECT_H

using namespace std;

class GameObject {
protected:
    string name;
public:
    GameObject(string name);
    virtual void performWithObject(GameObject *gameObject) = 0;
    virtual string getName();
};


#endif //STORY_GAME_GAMEOBJECT_H
