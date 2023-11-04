#include "includes.h"

using namespace std;

bool directoryExists(const wstring& path) {
    DWORD fileAttributes = GetFileAttributesW(path.c_str());
    return (fileAttributes != INVALID_FILE_ATTRIBUTES && (fileAttributes & FILE_ATTRIBUTE_DIRECTORY));
}

bool createDirectory(const wstring& path) {
    return CreateDirectoryW(path.c_str(), NULL) || ERROR_ALREADY_EXISTS == GetLastError();
}

bool downloadFile(const wstring& url, const wstring& destinationPath) {
    if (URLDownloadToFileW(NULL, url.c_str(), destinationPath.c_str(), 0, NULL) == S_OK) {
        return true;
    }
    return false;
}
