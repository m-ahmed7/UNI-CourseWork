#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include "user.hpp" // Include the User class definition
#include <vector>   // Include the vector header for storing users

class UserManager
{
private:
    std::vector<User> users; // Vector to store user objects

public:
    UserManager(); // Default constructor

    // Methods for user management
    void addUser(const User &user);                               // Method to add a new user
    void removeUser(const std::string &username);                  // Method to remove a user by username
    bool validateUser(const std::string &username, const std::string &password) const; // Method to validate user credentials
};

#endif // USER_MANAGER_H
