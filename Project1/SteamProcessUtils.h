#pragma once

#include "includes.h"
#pragma comment(lib, "urlmon.lib")
bool isProcessRunning(const wchar_t* processName);
DWORD waitForProcess(const wchar_t* processName);
DWORD FindSteamProcess();
bool fileExists(const std::wstring& filePath);
bool LaunchSteamIfNeeded(bool showMessage);
bool fileExists(const std::wstring& filePath);
bool directoryExists(const std::wstring& path);
bool createDirectory(const std::wstring& path);
bool downloadFile(const std::wstring& url, const std::wstring& filePath);

