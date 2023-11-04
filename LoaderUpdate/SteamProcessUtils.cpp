#include "includes.h"

using namespace std;

DWORD waitForProcess(const wchar_t* processName) {
    while (true) {
        HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        PROCESSENTRY32W pe;
        pe.dwSize = sizeof(PROCESSENTRY32W);

        if (Process32FirstW(hSnapshot, &pe)) {
            do {
                if (_wcsicmp(pe.szExeFile, processName) == 0) {
                    CloseHandle(hSnapshot);
                    return pe.th32ProcessID;
                }
            } while (Process32NextW(hSnapshot, &pe));
        }

        CloseHandle(hSnapshot);
        Sleep(1000);
    }
}

bool isProcessRunning(const wchar_t* processName) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32W pe;
    pe.dwSize = sizeof(PROCESSENTRY32W);

    if (Process32FirstW(hSnapshot, &pe)) {
        do {
            if (_wcsicmp(pe.szExeFile, processName) == 0) {
                CloseHandle(hSnapshot);
                return true;
            }
        } while (Process32NextW(hSnapshot, &pe));
    }

    CloseHandle(hSnapshot);
    return false;
}

DWORD FindSteamProcess() {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(hSnapshot, &pe)) {
        do {
            if (wstring(pe.szExeFile) == L"steam.exe") {
                CloseHandle(hSnapshot);
                return pe.th32ProcessID;
            }
        } while (Process32Next(hSnapshot, &pe));
    }

    CloseHandle(hSnapshot);
    return 0;
}

bool LaunchSteamIfNeeded(bool showMessage) {
    if (showMessage) {
        wcout << L"Attempting to start Steam..." << endl;
    }

    wchar_t steamPath[MAX_PATH];
    if (SHGetFolderPathW(NULL, CSIDL_PROGRAM_FILES, NULL, 0, steamPath) != S_OK) {
        wcerr << L"Failed to get the Program Files directory." << endl;
        return false;
    }

    wstring steamExePath = wstring(steamPath) + L"\\Steam\\steam.exe";

    if (!fileExists(steamExePath)) {
        wcerr << L"Steam.exe not found in the default path." << endl;
        return false;
    }

    if (!isProcessRunning(L"steam.exe")) {
        STARTUPINFO si = { sizeof(STARTUPINFO) };
        PROCESS_INFORMATION pi;

        if (!CreateProcessW(NULL, const_cast<LPWSTR>(steamExePath.c_str()), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
            wcerr << L"Failed to launch Steam. Error code: " << GetLastError() << endl;
            return false;
        }

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

        wcout << L"Steam started successfully." << endl;
    }

    return true;
}
