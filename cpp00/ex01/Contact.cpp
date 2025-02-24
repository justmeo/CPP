#include "Contact.hpp"

Contact::Contact() {
    // You can initialize variables here if you want
}

Contact::~Contact() {
    // No dynamic allocation -> nothing special to clean up
}

// Setters
void Contact::setFirstName(const std::string &str)     { this->firstName = str; }
void Contact::setLastName(const std::string &str)      { this->lastName = str; }
void Contact::setNickname(const std::string &str)      { this->nickname = str; }
void Contact::setPhoneNumber(const std::string &str)   { this->phoneNumber = str; }
void Contact::setDarkestSecret(const std::string &str) { this->darkestSecret = str; }

// Getters
std::string Contact::getFirstName() const      { return this->firstName; }
std::string Contact::getLastName() const       { return this->lastName; }
std::string Contact::getNickname() const       { return this->nickname; }
std::string Contact::getPhoneNumber() const    { return this->phoneNumber; }
std::string Contact::getDarkestSecret() const  { return this->darkestSecret; }
