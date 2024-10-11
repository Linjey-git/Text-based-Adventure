//
// Created by serhi on 28.03.2023.
//

#include "PageMap.h"


/*
 *
 * Displays debug info about Page by key
 *
 * */
void PageMap::displayDebug(string key) {
    Page *page = getPage(key);

    cout << "key: " << page->getName()
         << "\ndescription: " << page->getDescription()
         << "\nentity: " << page->getPageEntity()->getName()
         << "\n";

    for (int i = 0; i < page->getOptions().size(); ++i) {
        cout << i << ". " << page->getOptions()[i].description << " // " << page->getOptions()[i].behavior << " // "
             << page->getOptions()[i].nextPage << endl;
    }
}


/*
 *
 * Parses data from file to right standard of Page object
 *
 * */
void PageMap::parse(const char type, string line) {
    switch (type) {
        case 'k': {
            fields.temp_key = line;
            break;
        }
        case 'd': {
            fields.temp_description = line;
            break;
        }
        case 'o': {
            Option temp_option;
            string option_part;
            stringstream ss(line);
            int counter = 0;
            while (getline(ss, option_part, '|')) {
                switch (counter) {
                    case 0: {
                        temp_option.description = option_part;
                        counter++;
                        break;
                    }
                    case 1: {
                        temp_option.behavior = option_part[0];
                        counter++;
                        break;
                    }
                    case 2: {
                        temp_option.nextPage = option_part;
                        counter++;
                        break;
                    }
                }
            }
            fields.temp_options.push_back(temp_option);
            break;
        }
        case 'e': {
            fields.temp_entity_name = line;
            break;
        }
    }
}

/*
 *
 * Right adding a new just read Page object to map
 *
 * */
void PageMap::addObj() {
    if (entityMap == nullptr) {
        throw std::invalid_argument("Need fill pointer entityMap before use");
    }
    addPage(new Page(fields.temp_key,
                     fields.temp_description,
                     fields.temp_options,
            // need check for nullprt for entityMap
                     entityMap->getEntity(fields.temp_entity_name)));
    fields.clearFields();
}

/*
 *
 * Returns PageMap's size
 *
 * */
int PageMap::getSize() {
    return pages.size();
}


/*
 *
 * Returns Page from PageMap by key
 *
 * */
Page *PageMap::getPage(string key) {
    try {
        return pages[key];
    } catch (out_of_range) {
        cout << "Wrong key!\nCheck key's spelling!\n";
    }
    return nullptr;
}


/*
 *
 * Adds Page to PageMap
 *
 * */
void PageMap::addPage(Page *page) {

    pages.insert(make_pair(page->getName(), page));
}

PageMap::PageMap() {
    this->read_file("../data/pages.dat");
}

/*
 *
 * Displays Page from PageMap by key
 *
 * */
void PageMap::display_page(string key) {
    Page *page = getPage(key);

    cout << "\n";
    cout << page->getDescription()
         << "\n\n";
    if (!page->getPageEntity()->empty()) {
        page->getPageEntity()->display_entity();
    }
    cout << "\n";
    for (int i = 0; i < page->getOptions().size(); ++i) {
        cout << i << ". " << page->getOptions()[i].description << "\n";
    }

}


/*
 *
 * Method returns next Page's key, detects behavior of selected Option and call the save_game() function
 *
 * */
string PageMap::next_page(Page *page, char choice, Player *player, int (*main)()) {
    string next_page = page->getName();
    if (isdigit(choice)) {
        if ((choice - '0') < page->getOptions().size() && (choice - '0') >= 0) {
            next_page = page->getOptions()[choice - '0'].nextPage;

            switch (page->getOptions()[choice - '0'].behavior) {
                case 'p': {
                    if (player->has_item(page->getPageEntity()->getEntityItem()->getType())) {
                        page->getPageEntity()->getEntityItem()->set_basic_stats(player);
                    }
                    page->getPageEntity()->performWithObject(player);
                    page->getPageEntity()->getEntityItem()->performWithObject(player);
                    break;
                }
                case 'a': {
                    player->performWithObject(page->getPageEntity());
                    break;
                }
                case 'e': {
                    cout << "=============\n\n";
                    main();
                    break;
                }
            }
        } else {
            cout << "Wrong character!" << endl;
            next_page = page->getName();
        }
    } else {
        switch (choice) {
            case 's': {
                player->save_game(page->getName());
                next_page = page->getName();
                break;
            }
            case 'e': {
                ::exit(0);
            }
            default: {
                cout << "Wrong character!" << endl;
                next_page = page->getName();
            }
        }
    }


    return next_page;
}


/*
 *
 * Load a saved process from file by reading it
 *
 * */
string PageMap::load_game(Player *player) {
    const string file_source = "../data/saves.dat";
    string temp_line;
    string page_key;
    vector<Item *> inventory;

    fstream fs;
    fs.open(file_source);
    if (fs.is_open()) {
        cout << "File is found!\n";
        while (getline(fs, temp_line)) {
            if (temp_line != "end") {
                char type = temp_line[0];
                temp_line.erase(0, 2);
                switch (type) {
                    case 'p': {
                        page_key = temp_line;
                        break;
                    }
                    case 'n': {
                        player->setName(temp_line);
                        break;
                    }
                    case 'h': {
                        player->setHp(stoi(temp_line));
                        break;
                    }
                    case 'a' : {
                        player->setArmour(stoi(temp_line));
                        break;
                    }
                    case 'd': {
                        player->setDamage(stoi(temp_line));
                        break;
                    }
                    case 'i': {
                        Item *temp_item;
                        string item_name;
                        stringstream ss(temp_line);
                        while (getline(ss, item_name, '|')) {
                            temp_item = this->entityMap->getItemMap()->getItem(item_name);
                            inventory.push_back(temp_item);
                        }
                        player->setInventory(inventory);
                    }
                }
                // call function
            } else {
                return page_key;
            }
        }
        fs.close();
    }
}