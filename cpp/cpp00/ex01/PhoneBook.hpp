
#pragma once

#include "Contact.hpp"
#define MAX_SIZE 8


class PhoneBook {
public:
    PhoneBook();

    void AddContact(const Contact& contact);
    void DisplayContacts() const;
    void DisplayContactbyIndex(int idx) const;

private:
    int size, last_idx;
    Contact contacts[MAX_SIZE];
};
