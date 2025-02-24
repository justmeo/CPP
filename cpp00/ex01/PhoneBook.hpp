#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int     nextIndex;     // The index where the next contact will be stored
    int     totalContacts; // Total number of contacts added (may exceed 8 if we cycle)

public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContacts() const;

private:
    void displayContactsList() const;
    void displayContactInfo(int index) const;
    std::string truncateField(const std::string &field) const;
};

#endif
