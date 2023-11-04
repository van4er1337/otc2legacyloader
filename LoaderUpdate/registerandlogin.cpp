#include "registerandlogin.h"
#include <fstream>
#include <iostream>
#include "E:\1\httplib.h" // Ïóòü ê áèáëèîòåêå httplib



bool registerUser(const std::string& username, const std::string& password) {
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
            return true; // Ïîëüçîâàòåëü äîáàâëåí
        }
        else {
            std::cout << "Failed to add user." << std::endl;
            return false; // Íå óäàëîñü äîáàâèòü ïîëüçîâàòåëÿ
        }
    }
    else {
        std::cout << "Failed to connect to the server." << std::endl;
        return false; // Îøèáêà ñîåäèíåíèÿ
    }
}


bool authenticateUser(const std::string& username, const std::string& password) {
    httplib::Client cli("your website");

    std::string query = "/Login.php?username=" + username + "&password=" + password;

    auto res = cli.Get(query.c_str());

    if (res && res->status == 200) {
        std::string response_body = res->body;
        std::cout << "Response body: " << response_body << std::endl;

        if (response_body == "Yes!") {
            std::cout << "Yes!" << std::endl;
            return true; // Ïîëüçîâàòåëü àóòåíòèôèöèðîâàí
        }
        else {
            std::cout << "Invalid username or password." << std::endl;
            return false; // Íåóäà÷íàÿ àóòåíòèôèêàöèÿ
        }
    }
    else {
        std::cout << "Failed to connect to the server." << std::endl;
        return false; // Îøèáêà ñîåäèíåíèÿ
    }
}
