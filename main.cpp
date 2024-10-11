#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#include "map/SerializedMap.h"
#include "item/Item.h"
#include "map/PageMap.h"
#include "Player.h"

using namespace std;

Player *set_new_player();

void start_new_game();

void play(string page_key, Player *player);

void load_old_game();

const string START_KEY = "awakening_in_forest";
PageMap pm = PageMap();

struct Save {
    string save_title;
    string player_name;

    /*
     *
     * Display last save
     *
     * */
    void display_save() {
        cout << "==================================\n";
        cout << "Title: " << save_title << "\n"
             << "Player: " << player_name << endl;
        cout << "==================================\n";
    }
};

/*
 *
 * Main menu
 *
 * */
int main() {

    char choice;
    do {
        cout << "0 - New Game\n"
             << "1 - Load Game\n"
             << "2 - Exit Game\n"
             << "your choice: ";
        cin >> choice;
        if (isdigit(choice)) {
            if (choice - '0' <= 2 && choice - '0' >= 0) {
                break;
            }
        }
        cout << "Wrong character!" << endl;
    } while (true);

    switch (choice) {
        case '0': {
            start_new_game();
            break;
        }
        case '1' : {
            load_old_game();
            break;
        }
        case '2' : {
            ::exit(0);
        }
    }
    return 0;
}


/*
 *
 * Creating a new game
 *
 * */
void start_new_game() {
    Player *player = set_new_player();
    string current_page_key = START_KEY;

    play(current_page_key, player);
}


/*
 *
 * Displaying last save and after that its load
 *
 * */
void load_old_game() {
    Player *player = new Player("-", 0, 0, 0);
    string page_key = pm.load_game(player);
    Save final_save = {pm.getPage(page_key)->getDescription().substr(0, 50) + "...", player->getName()};
    final_save.display_save();
    cout << "Press any key to load...\n";
    system("pause");
    play(page_key, player);

}

/*
 *
 * Creating a new Player
 *
 * */
Player *set_new_player() {
    string name;
    cout << "Write a name of yours: ";
    cin >> name;
    Player *player = new Player(name, 5, 10, 3);
    return player;
}


/*
 *
 * The сore method where the Pages are displayed according to the Player's choice
 *
 * */
void play(string page_key, Player *player) {
    char choice;
    int score = 0;
    do {
        cout << "\n";
        for (int i = 0; i < 50; ++i) {
            cout << "==";
        }
        player->display_player();
        pm.display_page(page_key);
        cout << "=========================\n          MENU\n========================="
             << "\ns - Save Game"
             << "\ne - Exit Game"
             << "\n============="
             << "\nyour choice: ";
        cin >> choice;
        page_key = pm.next_page(pm.getPage(page_key), choice, player, &main);
        score++;
    } while (player->getHp() > 0);
    cout << "======================"
         << "\n\n" << player->getName() << "'s score: " << score
         << "\nYou were defeated!"
         << "\nGame Over\n\n" << endl;
    main();
}

