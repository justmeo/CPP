#include "PhoneBook.hpp"
#include <iomanip> // for std::setw, std::right

PhoneBook::PhoneBook() : nextIndex(0), totalContacts(0) {}

PhoneBook::~PhoneBook() {}

// ----------------------------------
//             ADD CONTACT
// ----------------------------------
void PhoneBook::addContact() {
    Contact newContact;
    std::string input;

    // Prompt user for each field:
    std::cout << "Enter First Name: ";
    if (!std::getline(std::cin, input) || input.empty()) {
        std::cout << "Invalid input. Contact not added.\n";
        return;
    }
    newContact.setFirstName(input);

    std::cout << "Enter Last Name: ";
    if (!std::getline(std::cin, input) || input.empty()) {
        std::cout << "Invalid input. Contact not added.\n";
        return;
    }
    newContact.setLastName(input);

    std::cout << "Enter Nickname: ";
    if (!std::getline(std::cin, input) || input.empty()) {
        std::cout << "Invalid input. Contact not added.\n";
        return;
    }
    newContact.setNickname(input);

    std::cout << "Enter Phone Number: ";
    if (!std::getline(std::cin, input) || input.empty()) {
        std::cout << "Invalid input. Contact not added.\n";
        return;
    }
    newContact.setPhoneNumber(input);

    std::cout << "Enter Darkest Secret: ";
    if (!std::getline(std::cin, input) || input.empty()) {
        std::cout << "Invalid input. Contact not added.\n";
        return;
    }
    newContact.setDarkestSecret(input);

    // Store new contact in the array
    this->contacts[this->nextIndex] = newContact;

    // Increment counters
    this->nextIndex = (this->nextIndex + 1) % 8; 
    if (this->totalContacts < 8)
        this->totalContacts++;
    
    std::cout << "Contact added successfully!\n";
}

// ----------------------------------
//            SEARCH CONTACTS
// ----------------------------------
void PhoneBook::searchContacts() const {
    if (this->totalContacts == 0) {
        std::cout << "PhoneBook is empty! Add a contact first.\n";
        return;
    }
    // 1) Display the list of contacts
    displayContactsList();

    // 2) Prompt for index
    std::cout << "Enter the index of the contact to display: ";
    std::string indexStr;
    if (!std::getline(std::cin, indexStr)) {
        std::cout << "Invalid input.\n";
        return;
    }

    // Convert indexStr to integer
    int index = 0;
    try {
        index = std::stoi(indexStr);
    } catch (...) {
        std::cout << "Invalid index.\n";
        return;
    }

    // Validate index
    if (index < 0 || index >= this->totalContacts) {
        std::cout << "Index out of range.\n";
    } else {
        displayContactInfo(index);
    }
}

// ----------------------------------
//        DISPLAY CONTACTS LIST
// ----------------------------------
void PhoneBook::displayContactsList() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    // The array may have been overwritten in circular fashion,
    // but the first `totalContacts` are valid. 
    // Because we are storing in a circular way, the "oldest" contact 
    // might not be at index 0 in the array. So let’s figure it out:

    // The contact that was added first is at nextIndex if totalContacts == 8.
    // If totalContacts < 8, they are just in [0..totalContacts-1].
    
    // We'll figure out the "start" for a linear display so that the
    // oldest contact is displayed as index 0, next oldest is 1, etc.
    int startIndex = 0;
    if (this->totalContacts == 8) {
        // If we have 8 contacts, the oldest is the nextIndex in the ring
        startIndex = this->nextIndex;
    }

    for (int i = 0; i < this->totalContacts; i++) {
        // Real index in the contacts array
        int realIndex = (startIndex + i) % 8;

        // Print i as the "display index" so user sees 0..7
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncateField(this->contacts[realIndex].getFirstName()) << "|";
        std::cout << std::setw(10) << truncateField(this->contacts[realIndex].getLastName()) << "|";
        std::cout << std::setw(10) << truncateField(this->contacts[realIndex].getNickname()) << std::endl;
    }
}

// ----------------------------------
//       DISPLAY SINGLE CONTACT
// ----------------------------------
void PhoneBook::displayContactInfo(int index) const {
    // We need to map the "display index" (0..totalContacts-1) 
    // back to the real position in the array.
    int startIndex = 0;
    if (this->totalContacts == 8) {
        startIndex = this->nextIndex;
    }
    int realIndex = (startIndex + index) % 8;

    std::cout << "First Name:     " 
              << this->contacts[realIndex].getFirstName() << std::endl;
    std::cout << "Last Name:      " 
              << this->contacts[realIndex].getLastName() << std::endl;
    std::cout << "Nickname:       " 
              << this->contacts[realIndex].getNickname() << std::endl;
    std::cout << "Phone Number:   " 
              << this->contacts[realIndex].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " 
              << this->contacts[realIndex].getDarkestSecret() << std::endl;
}

// ----------------------------------
//       TRUNCATE / FORMAT FIELDS
// ----------------------------------
std::string PhoneBook::truncateField(const std::string &field) const {
    // If field is longer than 10 chars, we return first 9 + "."
    if (field.length() > 10) {
        return field.substr(0, 9) + ".";
    }
    return field;
}
