#include "adminmanager.hpp" //include header file for admin manager

AdminManager::AdminManager() {}

void AdminManager::addAdmin(const Admin &admin)//function to add admin to admins vector
{
    admins.push_back(admin);
}

void AdminManager::removeAdmin(const std::string &username)//remove admin from admins vector
{
    for (auto it = admins.begin(); it != admins.end(); ++it)
    {
        if (it->getUsername() == username)
        {
            admins.erase(it);
            break;
        }
    }
}

bool AdminManager::validateAdmin(const std::string &username, const std::string &password) const//check if the admin's login details are valid
{
    for (const auto &admin : admins)
    {
        if (admin.getUsername() == username && admin.getPassword() == password)
        {
            return true;
        }
    }
    return false;
}