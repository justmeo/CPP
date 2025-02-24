#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    // Contact information
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    // Constructors / Destructor
    Contact();
    ~Contact();

    // Setters
    void setFirstName(const std::string &str);
    void setLastName(const std::string &str);
    void setNickname(const std::string &str);
    void setPhoneNumber(const std::string &str);
    void setDarkestSecret(const std::string &str);

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif
