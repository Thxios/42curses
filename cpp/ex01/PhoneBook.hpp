
#pragma once

#include "Contact.hpp"
#define MAX_SIZE 8


class PhoneBook {
public:
    PhoneBook(): size(0) {}
    PhoneBook(const PhoneBook& other);
    PhoneBook& operator=(const PhoneBook& other);
    ~PhoneBook() {}

    void AddContact(const Contact& contact);
    void DisplayContacts() const;
    void DisplayContactbyIndex(int idx) const;

private:
    int size;
    Contact contacts[MAX_SIZE];
};
