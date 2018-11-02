#include <map>

class Dictionary {
private:
    std::map<std::string, std::string> dictionary;
    std::map<std::string, std::string>::iterator it;

public:
    Dictionary(std::string);
    void printAll();
    void newWord();
    void findWord();
};

