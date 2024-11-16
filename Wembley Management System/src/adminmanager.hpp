#ifndef ADMIN_MANAGER_H
#define ADMIN_MANAGER_H

#include "admin.hpp" // Include necessary header file for Admin class
#include <vector>    // Include necessary header file for std::vector

// Declaration of the AdminManager class
class AdminManager
{
private:
    std::vector<Admin> admins; // Vector to store admin objects

public:
    // Constructor
    AdminManager();

    // Method to add an admin to the vector
    void addAdmin(const Admin &admin);

    // Method to remove an admin from the vector by username
    void removeAdmin(const std::string &username);

    // Method to validate admin login credentials
    bool validateAdmin(const std::string &username, const std::string &password) const;
};

#endif // ADMIN_MANAGER_H
