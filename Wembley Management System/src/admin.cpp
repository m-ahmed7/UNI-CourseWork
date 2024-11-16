#include "admin.hpp"

// Default constructor
Admin::Admin() {}

// Parameterized constructor
Admin::Admin(std::string username, std::string password)
    : username(username), password(password) {}

// Getter method for username
std::string Admin::getUsername() const
{
    return username;
}

// Setter method for username
void Admin::setUsername(const std::string &username)
{
    this->username = username;
}

// Getter method for password
std::string Admin::getPassword() const
{
    return password;
}

// Setter method for password
void Admin::setPassword(const std::string &password)
{
    this->password = password;
}
