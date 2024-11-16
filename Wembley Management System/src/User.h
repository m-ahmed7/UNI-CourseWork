#ifndef WEMBLEYMANAGEMENTSYSTEM_USER_H
#define WEMBLEYMANAGEMENTSYSTEM_USER_H

#include <string>

class User {
protected:
    std::string username;
    std::string password;
    int userID;

public:
    User(const std::string& username, const std::string& password, int userID);
    virtual void login() = 0;
    virtual void logout() = 0;
    virtual ~User();

    std::string getUsername() const;
    void setUsername(const std::string& newUsername);
};


#endif //WEMBLEYMANAGEMENTSYSTEM_USER_H
