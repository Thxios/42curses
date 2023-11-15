
#pragma once

#include <string>


class Contact {
public:
    Contact() {}
    Contact(std::string first, 
            std::string last, 
            std::string nick, 
            std::string ph_num, 
            std::string sec);
    Contact(const Contact& other);
    Contact& operator=(const Contact& other);
    ~Contact() {}

    std::string GetFirstName() const;
    std::string GetLastName() const;
    std::string GetNickame() const;
    std::string GetPhoneNumber() const;
    std::string GetSecret() const;

private:
    std::string first_name, last_name, nickname;
    std::string phone_number, secret;
};
