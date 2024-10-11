//
// Created by serhi on 27.03.2023.
//

#include "SerializedMap.h"

//void parse(const char type, string line);
//void addObj();

/*
 *
 * A single standard for reading from a file
 *
 * */
void SerializedMap::read_file(const string file_source) {
    string temp_line;

    fstream fs;
    fs.open(file_source);
    if (fs.is_open()) {
        cout << "File is found!\n";
        while (getline(fs, temp_line)) {
            if (temp_line != "end") {
                char type = temp_line[0];
                temp_line.erase(0, 2);
                // call function
                parse(type, temp_line);
            } else {
                addObj();
            }
        }
        fs.close();
    } else {
        cout << "File was not found!\n";
    }
}