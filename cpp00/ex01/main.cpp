#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            std::cout << "Error reading input.\n";
            return 1; // Something went wrong with stdin
        }

        if (command == "ADD") {
            phoneBook.addContact();
        } 
        else if (command == "SEARCH") {
            phoneBook.searchContacts();
        } 
        else if (command == "EXIT") {
            std::cout << "Exiting program. Contacts are lost forever!\n";
            break;
        } 
        else {
            std::cout << "Invalid command. Please try again.\n";
        }
    }
    return 0;
}
