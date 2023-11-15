
#include "Contact.hpp"


Contact::Contact(
        std::string first, 
        std::string last, 
        std::string nick, 
        std::string ph_num, 
        std::string sec) 
    : first_name(first), last_name(last), nickname(nick), 
    phone_number(ph_num), secret(sec) {}


Contact::Contact(const Contact& other)
    : first_name(other.first_name), 
    last_name(other.last_name), 
    nickname(other.nickname), 
    phone_number(other.phone_number), 
    secret(other.secret) {}


Contact& Contact::operator=(const Contact& other) {
    first_name = other.first_name;
    last_name = other.last_name;
    nickname = other.nickname;
    phone_number = other.phone_number;
    secret = other.secret;
    return *this;
}


std::string Contact::GetFirstName() const {
    return first_name;
}


std::string Contact::GetLastName() const {
    return last_name;
}


std::string Contact::GetNickame() const {
    return nickname;
}


std::string Contact::GetPhoneNumber() const {
    return phone_number;
}


std::string Contact::GetSecret() const {
    return secret;
}



