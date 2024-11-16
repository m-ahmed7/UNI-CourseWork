#include "usermanager.hpp"

// Default constructor
UserManager::UserManager() {}

// Method to add a new user
void UserManager::addUser(const User &user)
{
    users.push_back(user);
}

// Method to remove a user by username
void UserManager::removeUser(const std::string &username)
{
    for (auto it = users.begin(); it != users.end(); ++it)
    {
        if (it->getUsername() == username)
        {
            users.erase(it);
            break;
        }
    }
}

// Method to validate user credentials
bool UserManager::validateUser(const std::string &username, const std::string &password) const
{
    for (const auto &user : users)
    {
        if (user.getUsername() == username && user.getPassword() == password)
        {
            return true;
        }
    }
    return false;
}
