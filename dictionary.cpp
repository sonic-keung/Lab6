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

        dictionary.insert(std::make_pair(words, definition));
    }
}

// print all of the values in the map
void Dictionary::printAll() {
    for (auto& elem : dictionary) {
        std::cout << elem.first << " - " << elem.second << std::endl;
    }
}

// find a word in the map
void Dictionary::findWord() {
    std::cout << "Enter word to find" << std::endl;
    std::string findWord;
    std::cin >> findWord;

    it = dictionary.find(findWord);

    // find word
    if (it != dictionary.end()) {
        std::cout << "Definition: " << it->second << std::endl;
    } else {
        std::cout << "can't find word" << std::endl;
    }

}

// create a new word in the map.
void Dictionary::newWord() {
    std::string myWord;
    std::string wordDef;

    std::cout << "Enter a new word" << std::endl;
    std::cin >> myWord;

    auto itr = dictionary.find(myWord);


    // add new word to map
    if (itr == dictionary.end()) {
        std::cout << "Enter a definition for the new word" << std::endl;
        std::cin.ignore();
        getline(std::cin, wordDef);

        dictionary.insert(make_pair(myWord, wordDef));

        std::ofstream out;
        out.open("../dictionary.txt", std::ios::app);
        out << myWord << " - " << wordDef << std::endl;

        std::cout << "Word has been added" << std::endl;
    }

    while (itr != dictionary.end()) {
        std::cout << "the word already exists" << std::endl;
        std::cout << "Enter another word" << std::endl;
        std::cin >> myWord;
        auto itr2 = dictionary.find(myWord);

        if (itr2 == dictionary.end()) {
            std::cout << "Enter a definition for the new word" << std::endl;
            std::cin.ignore();
            getline(std::cin, wordDef);

            dictionary.insert(make_pair(myWord, wordDef));

            std::ofstream out;
            out.open("../dictionary.txt", std::ios::app);
            out << myWord << " - " << wordDef << std::endl;

            std::cout << "Word has been added" << std::endl;
            break;
        }
    }
}



