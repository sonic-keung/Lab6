#include <map>
#pragma once
class Dictionary {
private:
    std::map<std::string, std::string> insertWord;

public:
    Dictionary(std::string);
    void printAll();
    void newWord();
    void findWord();
};

