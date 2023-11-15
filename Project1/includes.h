#pragma comment(lib, "urlmon.lib")
#include <iostream>
#include <string>
#include <algorithm>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <fstream>
#include <urlmon.h>
#include <locale>
#include <Shlobj.h>
#include <unordered_map>
#include <sstream>
#include <ShlObj_core.h>
#include <TlHelp32.h>


#include "registerandlogin.h"
#include "SteamProcessUtils.h"
#include "Injector.h"
#include "D:\1\httplib.h"
#include <msclr/marshal_cppstd.h>

bool fileExists(const std::wstring& filePath);
