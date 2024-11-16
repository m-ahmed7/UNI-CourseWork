#ifndef ADMIN_H
#define ADMIN_H

#include <string>

// Declaration of the Admin class
class Admin
{
private:
    std::string username; // Username of the admin
    std::string password; // Password of the admin

public:
    // Constructors
    Admin(); // Default constructor
    Admin(std::string username, std::string password); // Parameterized constructor

    // Getter and setter methods for username
    std::string getUsername() const;
    void setUsername(const std::string &username);

    // Getter and setter methods for password
    std::string getPassword() const;
    void setPassword(const std::string &password);
};

#endif // ADMIN_H
