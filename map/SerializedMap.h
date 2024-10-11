//
// Created by serhi on 27.03.2023.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#ifndef STORY_GAME_SERIALIZEDMAP_H
#define STORY_GAME_SERIALIZEDMAP_H

using namespace std;


class SerializedMap {
protected:
    virtual void parse(const char type, string line) = 0;

    virtual void addObj() = 0;

public:
    virtual void displayDebug(string name) = 0;

    void read_file(const string file_source);
};


#endif //STORY_GAME_SERIALIZEDMAP_H
