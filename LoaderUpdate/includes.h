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

#include "registerandlogin.h"  // Здесь должен быть ваш заголовочный файл
#include "SteamProcessUtils.h" // Подключите нужные заголовки сразу после системных заголовков Windows

#include "Injector.h"
#include "Directory.h"
#include "E:\1\httplib.h"
