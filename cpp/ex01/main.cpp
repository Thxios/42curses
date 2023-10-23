
#include <iostream>
#include <string>
#include "PhoneBook.hpp"


int main() {

    std::string command;
    PhoneBook book;

    while (true) {
        std::cout << "enter command" << std::endl;
        std::cin >> command;
        if (command == "ADD") {
            std::cout << "enter 5 fields: "
            << "first name, last name, nickname, "
            << "phone number, secret" << std::endl;
            std::string fir, last, nname, ph_num, sec;
            std::cin.ignore();
            std::getline(std::cin, fir);
            std::getline(std::cin, last);
            std::getline(std::cin, nname);
            std::getline(std::cin, ph_num);
            std::getline(std::cin, sec);
            book.AddContact(Contact(
                fir, last, nname, ph_num, sec
            ));
        }
        else if (command == "SEARCH") {
            book.DisplayContacts();
            int idx;
            std::cout << "enter index to search" << std::endl;
            std::cin >> idx;
            book.DisplayContactbyIndex(idx);
        }
        else if (command == "EXIT") {
            break;
        }
        std::cout << std::endl;
    }
}
