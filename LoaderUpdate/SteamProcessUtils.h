#pragma once

#include "includes.h"

bool isProcessRunning(const wchar_t* processName);
DWORD waitForProcess(const wchar_t* processName);
DWORD FindSteamProcess();
bool fileExists(const std::wstring& filePath);
bool LaunchSteamIfNeeded(bool showMessage);

