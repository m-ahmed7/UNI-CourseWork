#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string password;

public:
    User(); // Default constructor
    User(std::string username, std::string password); // Parameterized constructor

    // Getter and setter methods for username
    std::string getUsername() const;
    void setUsername(const std::string& username);

    // Getter and setter methods for password
    std::string getPassword() const;
    void setPassword(const std::string& password);
};

#endif // USER_H
