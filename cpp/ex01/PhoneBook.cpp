
#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"



PhoneBook::PhoneBook(const PhoneBook& other)
: size(other.size), contacts(other.contacts) {}


PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
    size = other.size;
    for (int i = 0; i < other.size; i++) {
        contacts[i] = other.contacts[i];
    }
    return *this;
}


void PhoneBook::AddContact(const Contact& contact) {
    if (size >= MAX_SIZE) {
        std::cout << "PhoneBook is full" << std::endl;
        return;
    }
    contacts[size++] = contact;
}


std::string GetTruncated(const std::string& s, size_t n) {
    if (s.size() > n) {
        return s.substr(0, n - 1) + ".";
    }
    return s;
}


void PhoneBook::DisplayContacts() const {
    
    for (int i = 0; i < size; i++) {
        std::cout << "|";
        std::cout << std::setw(10) << i;
        std::cout << "|";

        std::cout << std::setw(10) 
            << GetTruncated(contacts[i].GetFirstName(), 10);
        std::cout << "|";

        std::cout << std::setw(10) 
            << GetTruncated(contacts[i].GetLastName(), 10);
        std::cout << "|";

        std::cout << std::setw(10) 
            << GetTruncated(contacts[i].GetNickame(), 10);
        std::cout << "|";
        std::cout << std::endl;
    }
}


void PhoneBook::DisplayContactbyIndex(int idx) const {
    if (idx < 0 && idx >= size) {
        std::cout << "invalid index: " << idx << std::endl;
        return;
    }
    std::cout << contacts[idx].GetFirstName() << std::endl;
    std::cout << contacts[idx].GetLastName() << std::endl;
    std::cout << contacts[idx].GetNickame() << std::endl;
    std::cout << contacts[idx].GetPhoneNumber() << std::endl;
    std::cout << contacts[idx].GetSecret() << std::endl;
}


