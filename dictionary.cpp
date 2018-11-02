#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <iterator>
#include <string>
#include "dictionary.hpp"

// insert words and definition in the map
Dictionary::Dictionary(std::string fileName) {
    std::ifstream file(fileName);
    std::string word;

    while (getline(file, word)) {
        std::string words = word.substr(0, word.find("-") - 1);
        std::string definition = word.substr(word.find("-") + 2);

        insertWord.insert(std::make_pair(words, definition));
    }
}

// print all of the values in the map
void Dictionary::printAll() {
    for (auto& elem : insertWord) {
        std::cout << elem.first << " - " << elem.second << std::endl;
    }
}

// find a word in the map
void Dictionary::findWord() {
    std::cout << "Enter word to find" << std::endl;
    std::string findWord;
    std::cin >> findWord;

    std::map<std::string, std::string>::iterator it = insertWord.find(findWord);

    // find word
    if (it->first != findWord) {
        std::cout << "can't find word" << std::endl;
    } else {
        std::cout << it->second << std::endl;
    }

}

// create a new word in the map.
void Dictionary::newWord() {
    std::cout << "Enter a new word" << std::endl;
    std::string myWord;
    std::cin >> myWord;
    std::string wordDef;

    std::map<std::string, std::string>::iterator it = insertWord.find(myWord);

    // add new word to map
    if (it->first != myWord) {
        std::cout << "Enter a definition for the entered word" << std::endl;
        std::cin.ignore();
        getline(std::cin, wordDef);
        insertWord.insert(make_pair(myWord, wordDef));
        std::cout << "Word has been added" << std::endl;
    }

    // if word exists in the map already
    while (it->first == myWord) {
        std::cout << "Word already exists" << std::endl;
        std::cout << "Enter another word" << std::endl;
        std::cin >> myWord;

        if (it->first != myWord) {
            std::cout << "Enter a definition for the entered word" << std::endl;
            std::cin.ignore();
            getline(std::cin, wordDef);
            insertWord.insert(make_pair(myWord, wordDef));
            std::cout << "Word has been added" << std::endl;
            break;
        }
    }

}


