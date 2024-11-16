#include "user.hpp"

// Default constructor
User::User() {}

// Parameterized constructor
User::User(std::string username, std::string password)
    : username(username), password(password) {}

// Getter method for username
std::string User::getUsername() const
{
    return username;
}

// Setter method for username
void User::setUsername(const std::string &username)
{
    this->username = username;
}

// Getter method for password
std::string User::getPassword() const
{
    return password;
}

// Setter method for password
void User::setPassword(const std::string &password)
{
    this->password = password;
}
