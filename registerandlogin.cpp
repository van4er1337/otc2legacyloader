#include "registerandlogin.h"
#include <fstream>
#include <iostream>
#include "D:\1\httplib.h" // Путь к библиотеке httplib


bool Project1::registerUserForm(const std::string& username, const std::string& password)
{
    if (username.length() < 4 || password.length() < 8) {
        std::cerr << "Username must be at least 4 characters and password at least 8 characters." << std::endl;
        return false;
    }

    httplib::Client cli("your website");

    std::string query = "/Register.php?username=" + username + "&password=" + password;

    auto res = cli.Get(query.c_str());

    if (res && res->status == 200) {
        std::string response_body = res->body;
        std::cout << "Response body: " << response_body << std::endl;

        if (response_body == "User added successfully!") {
            std::cout << "User added successfully!" << std::endl;
            return true; // Пользователь добавлен
        }
        else {
            std::cout << "Failed to add user." << std::endl;
            return false; // Не удалось добавить пользователя
        }
    }
    else {
        std::cout << "Failed to connect to the server." << std::endl;
        return false; // Ошибка соединения
    }
}

bool Project1::authenticateUserForm(const std::string& username, const std::string& password) // Removed the extra semicolon
{
    httplib::Client cli("your website");

    std::string query = "/Login.php?username=" + username + "&password=" + password;

    auto res = cli.Get(query.c_str());

    if (res && res->status == 200) {
        std::string response_body = res->body;
        std::cout << "Response body: " << response_body << std::endl;

        if (response_body == "Yes!") {
            std::cout << "Yes!" << std::endl;
            return true; // Пользователь аутентифицирован
        }
        else {
            std::cout << "Invalid username or password." << std::endl;
            return false; // Неудачная аутентификация
        }
    }
    else {
        std::cout << "Failed to connect to the server." << std::endl;
        return false; // Ошибка соединения
    }
}
