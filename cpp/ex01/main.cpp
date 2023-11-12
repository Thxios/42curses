
#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "PhoneBook.hpp"


bool getline_int(std::istream& in, int& n) {
    std::string s;
    if (!std::getline(in, s))
        return false;
    std::stringstream ss(s);
    ss >> n;
    if (ss.fail())
        return false;
    ss >> s;
    return (ss.fail());
}


int main() {

    std::string command;
    PhoneBook book;

    std::cout << "enter command" << std::endl;
    while (std::getline(std::cin, command)) {
        if (command == "ADD") {
            std::cout << "enter 5 fields: "
            << "first name, last name, nickname, "
            << "phone number, secret" << std::endl;
            std::string fir, last, nname, ph_num, sec;
            if (!std::getline(std::cin, fir)
            || !std::getline(std::cin, last)
            || !std::getline(std::cin, nname)
            || !std::getline(std::cin, ph_num)
            || !std::getline(std::cin, sec)) {
                std::cout << "eof" << std::endl;
                break;
            }
            book.AddContact(Contact(
                fir, last, nname, ph_num, sec
            ));
        }
        else if (command == "SEARCH") {
            book.DisplayContacts();
            int idx;
            std::cout << "enter index to search" << std::endl;
            if (!getline_int(std::cin, idx)) {
                std::cout << "invalid index" << std::endl;
            }
            else {
                book.DisplayContactbyIndex(idx);
            }
        }
        else if (command == "EXIT") {
            std::cout << "exit" << std::endl;
            break;
        }
        else {
            std::cout << "unknown command \"" << command << "\"" << std::endl;
        }
        std::cout << std::endl;
        std::cout << "enter command" << std::endl;
    }
}
