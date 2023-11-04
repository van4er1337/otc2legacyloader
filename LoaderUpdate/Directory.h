#pragma once

#include "includes.h"

bool directoryExists(const std::wstring& path);
bool createDirectory(const std::wstring& path);
bool downloadFile(const std::wstring& url, const std::wstring& destinationPath);
