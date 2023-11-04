#ifndef REGISTER_AND_LOGIN_H
#define REGISTER_AND_LOGIN_H

#include "includes.h"

struct UserData {
    std::string username;
    std::string password;
};
bool blockUserIP(const std::string& ipAddress, const std::string& reason);
bool registerUser(const std::string& username, const std::string& password);
bool authenticateUser(const std::string& username, const std::string& password);

#endif // REGISTER_AND_LOGIN_H
