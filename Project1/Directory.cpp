#include "includes.h"
#include "registerandlogin.h"
#include <chrono>
#include <thread>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace std;

bool directoryExists(const wstring& path) {
    DWORD fileAttributes = GetFileAttributesW(path.c_str());
    return (fileAttributes != INVALID_FILE_ATTRIBUTES && (fileAttributes & FILE_ATTRIBUTE_DIRECTORY));
}

bool createDirectory(const wstring& path) {
    return CreateDirectoryW(path.c_str(), NULL) || ERROR_ALREADY_EXISTS == GetLastError();
}

bool downloadFile(const wstring& url, const wstring& filePath) {
    try {
        WebClient^ webClient = gcnew WebClient();
        Uri^ uri = gcnew Uri(gcnew String(url.c_str()));

        webClient->DownloadFile(uri, gcnew String(filePath.c_str()));
        return true;
    }
    catch (Exception^ ex) {
        // Print an error message or log the exception details
        Console::Error->WriteLine("Error downloading file: " + ex->Message);
        return false;
    }
}

bool fileExists(const wstring& filePath) {
    DWORD fileAttributes = GetFileAttributesW(filePath.c_str());
    return (fileAttributes != INVALID_FILE_ATTRIBUTES);
}

