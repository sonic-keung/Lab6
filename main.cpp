#include <iostream>
#include <fstream>
#include <vector>
#include "dictionary.hpp"

void print_menu();

int main() {
    int selection;
    Dictionary d = Dictionary("../dictionary.txt");
    std::cout << "Enter a selection" << std::endl;
    // switch case menu
    while (selection != 4) {
        print_menu();
        std::cin >> selection;
        switch (selection) {
            case 1:
                d.printAll();
                break;
            case 2:
                d.findWord();
                break;
            case 3:
                d.newWord();
                break;
            case 4:
                std::cout<< "Exiting" << std::endl;
                break;
            default:
                std::cout << "Invalid choice, try again" << std::endl;
                break;
        }
    }
    return 0;
}

void print_menu() {
    std::cout << "1 - Print dictionary" << std::endl;
    std::cout << "2 - Find word definition" << std::endl;
    std::cout << "3 - Enter new word and definition" << std::endl;
    std::cout << "4 - Exit" << std::endl;
}
