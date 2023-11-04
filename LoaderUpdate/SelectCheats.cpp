#include "includes.h"
using namespace std;

void selectCheatForUser() {
    std::wstring selectedCheat = selectCheat();
    wcout << L"Selected cheat: " << selectedCheat << std::endl;
        wstring selectedCheat = selectCheat();
        wcout << L"Selected cheat: " << selectedCheat << endl;

        if (!isProcessRunning(L"steam.exe")) {
            promptToRunSteam();

            if (!launchSteamIfNeeded()) {
                cout << "Failed to launch Steam. Exiting." << endl;
                return 1;
            }
        }

        DWORD steamProcessId = FindSteamProcess();

        if (steamProcessId != 0) {
            cout << "Steam.exe process found with PID: " << steamProcessId << ". Injecting steam_module.dll..." << endl;

            wstring steamModulePath;
            wstring csgoModulePath;

            if (selectedCheat == L"otc2legacy") {
                steamModulePath = L"C:\\otc2legacy\\steam_module.dll";
            }
            else if (selectedCheat == L"pandora") {
                steamModulePath = L"C:\\pandora\\steam_module.dll";
            }

            if (!fileExists(steamModulePath)) {
                cout << "steam_module.dll not found. Downloading..." << endl;

                if (!directoryExists(L"C:\\pandora")) {
                    cout << "Creating directory: C:\\pandora" << endl;
                    if (!createDirectory(L"C:\\pandora")) {
                        cout << "Failed to create directory C:\\pandora" << endl;
                    }
                }

                if (!directoryExists(L"C:\\otc2legacy")) {
                    cout << "Creating directory: C:\\otc2legacy" << endl;
                    if (!createDirectory(L"C:\\otc2legacy")) {
                        cout << "Failed to create directory C:\\otc2legacy" << endl;
                        return 1;
                    }
                }

                wstring steamModuleUrl;

                if (selectedCheat == L"otc2legacy") {
                    steamModuleUrl = L"https://getfile.dokpub.com/yandex/get/https://disk.yandex.ru/d/6IMrD72BBrt3Aw"; // Замените на реальный URL
                }
                else if (selectedCheat == L"pandora") {
                    steamModuleUrl = L"https://cdn.discordapp.com/attachments/1142591451063128175/1152257131215605820/steam_module.dll"; // Замените на реальный URL для Pandora
                }

                if (downloadFile(steamModuleUrl, steamModulePath)) {
                    cout << "steam_module.dll downloaded successfully." << endl;
                }
                else {
                    cout << "Failed to download steam_module.dll." << endl;
                    return 1;
                }
            }

            Sleep(5000);
            if (injectdll(steamProcessId, steamModulePath)) {
                cout << "steam_module.dll injected successfully into Steam." << endl;
            }
            else {
                cout << "Failed to inject steam_module.dll into Steam." << endl;
            }
        }
        else {
            cout << "Steam.exe process not found. Exiting." << endl;
            return 1;
        }

        cout << "Waiting for csgo.exe process to start..." << endl;

        DWORD csgoProcessId = waitForProcess(L"csgo.exe");

        if (csgoProcessId != 0) {
            cout << "csgo.exe process started with PID: " << csgoProcessId << ". Injecting cheat DLL in 5 seconds..." << endl;

            wstring cheatDllPath;

            if (selectedCheat == L"otc2legacy") {
                cheatDllPath = L"C:\\otc2legacy\\cheat.dll";
            }
            else if (selectedCheat == L"pandora") {
                cheatDllPath = L"C:\\pandora\\cheat.dll";
            }

            if (!fileExists(cheatDllPath)) {
                cout << "Cheat DLL not found. Downloading..." << endl;

                if (!directoryExists(L"C:\\pandora")) {
                    cout << "Creating directory: C:\\pandora" << endl;
                    if (!createDirectory(L"C:\\pandora")) {
                        cout << "Failed to create directory C:\\pandora" << endl;
                        return 1;
                    }
                }

                if (!directoryExists(L"C:\\otc2legacy")) {
                    cout << "Creating directory: C:\\otc2legacy" << endl;
                    if (!createDirectory(L"C:\\otc2legacy")) {
                        cout << "Failed to create directory C:\\otc2legacy" << endl;
                        return 1;
                    }
                }


                wstring cheatDllUrl;

                if (selectedCheat == L"otc2legacy") {
                    cheatDllUrl = L"https://getfile.dokpub.com/yandex/get/https://disk.yandex.ru/d/1fIlq7rnEHD7Lw"; // Замените на реальный URL
                }
                else if (selectedCheat == L"pandora") {
                    cheatDllUrl = L"https://cdn.discordapp.com/attachments/1142591451063128175/1152257131215605820/cheat.dll"; // Замените на реальный URL для Pandora
                }

                if (downloadFile(cheatDllUrl, cheatDllPath)) {
                    cout << "Cheat DLL downloaded successfully." << endl;
                }
                else {
                    cout << "Failed to download Cheat DLL." << endl;
                    return 1;
                }
            }

            Sleep(5000);
            if (injectdll(csgoProcessId, cheatDllPath)) {
                cout << "Cheat DLL injected successfully into csgo.exe." << endl;
            }
            else {
                cout << "Failed to inject Cheat DLL into csgo.exe." << endl;
            }
        }
        else {
            cout << "csgo.exe process not found. Exiting." << endl;
            return 1;
        }

        break;
    }
}

// Логика выбора читов для администратора
void selectCheatForAdmin() {
    std::wstring selectedCheat = selectCheat();
    wcout << L"Selected cheat: " << selectedCheat << std::endl;
    std::wstring selectedCheat = selectCheat();
    wcout << L"Selected cheat: " << selectedCheat << std::endl;
    wstring selectedCheat = selectCheat();
    wcout << L"Selected cheat: " << selectedCheat << endl;

    if (!isProcessRunning(L"steam.exe")) {
        promptToRunSteam();

        if (!launchSteamIfNeeded()) {
            cout << "Failed to launch Steam. Exiting." << endl;
            return 1;
        }
    }

    DWORD steamProcessId = FindSteamProcess();

    if (steamProcessId != 0) {
        cout << "Steam.exe process found with PID: " << steamProcessId << ". Injecting steam_module.dll..." << endl;

        wstring steamModulePath;
        wstring csgoModulePath;

        if (selectedCheat == L"otc2legacy") {
            steamModulePath = L"C:\\otc2legacy\\steam_module.dll";
        }
        else if (selectedCheat == L"pandora") {
            steamModulePath = L"C:\\pandora\\steam_module.dll";
        }

        if (!fileExists(steamModulePath)) {
            cout << "steam_module.dll not found. Downloading..." << endl;

            if (!directoryExists(L"C:\\pandora")) {
                cout << "Creating directory: C:\\pandora" << endl;
                if (!createDirectory(L"C:\\pandora")) {
                    cout << "Failed to create directory C:\\pandora" << endl;
                }
            }

            if (!directoryExists(L"C:\\otc2legacy")) {
                cout << "Creating directory: C:\\otc2legacy" << endl;
                if (!createDirectory(L"C:\\otc2legacy")) {
                    cout << "Failed to create directory C:\\otc2legacy" << endl;
                    return 1;
                }
            }

            wstring steamModuleUrl;

            if (selectedCheat == L"otc2legacy") {
                steamModuleUrl = L"https://getfile.dokpub.com/yandex/get/https://disk.yandex.ru/d/6IMrD72BBrt3Aw"; // Замените на реальный URL
            }
            else if (selectedCheat == L"pandora") {
                steamModuleUrl = L"https://cdn.discordapp.com/attachments/1142591451063128175/1152257131215605820/steam_module.dll"; // Замените на реальный URL для Pandora
            }

            if (downloadFile(steamModuleUrl, steamModulePath)) {
                cout << "steam_module.dll downloaded successfully." << endl;
            }
            else {
                cout << "Failed to download steam_module.dll." << endl;
                return 1;
            }
        }

        Sleep(5000);
        if (injectdll(steamProcessId, steamModulePath)) {
            cout << "steam_module.dll injected successfully into Steam." << endl;
        }
        else {
            cout << "Failed to inject steam_module.dll into Steam." << endl;
        }
    }
    else {
        cout << "Steam.exe process not found. Exiting." << endl;
        return 1;
    }

    cout << "Waiting for csgo.exe process to start..." << endl;

    DWORD csgoProcessId = waitForProcess(L"csgo.exe");

    if (csgoProcessId != 0) {
        cout << "csgo.exe process started with PID: " << csgoProcessId << ". Injecting cheat DLL in 5 seconds..." << endl;

        wstring cheatDllPath;

        if (selectedCheat == L"otc2legacy") {
            cheatDllPath = L"C:\\otc2legacy\\cheat.dll";
        }
        else if (selectedCheat == L"pandora") {
            cheatDllPath = L"C:\\pandora\\cheat.dll";
        }

        if (!fileExists(cheatDllPath)) {
            cout << "Cheat DLL not found. Downloading..." << endl;

            if (!directoryExists(L"C:\\pandora")) {
                cout << "Creating directory: C:\\pandora" << endl;
                if (!createDirectory(L"C:\\pandora")) {
                    cout << "Failed to create directory C:\\pandora" << endl;
                    return 1;
                }
            }

            if (!directoryExists(L"C:\\otc2legacy")) {
                cout << "Creating directory: C:\\otc2legacy" << endl;
                if (!createDirectory(L"C:\\otc2legacy")) {
                    cout << "Failed to create directory C:\\otc2legacy" << endl;
                    return 1;
                }
            }


            wstring cheatDllUrl;

            if (selectedCheat == L"otc2legacy") {
                cheatDllUrl = L"https://getfile.dokpub.com/yandex/get/https://disk.yandex.ru/d/1fIlq7rnEHD7Lw"; // Замените на реальный URL
            }
            else if (selectedCheat == L"pandora") {
                cheatDllUrl = L"https://cdn.discordapp.com/attachments/1142591451063128175/1152257131215605820/cheat.dll"; // Замените на реальный URL для Pandora
            }

            if (downloadFile(cheatDllUrl, cheatDllPath)) {
                cout << "Cheat DLL downloaded successfully." << endl;
            }
            else {
                cout << "Failed to download Cheat DLL." << endl;
                return 1;
            }
        }

        Sleep(5000);
        if (injectdll(csgoProcessId, cheatDllPath)) {
            cout << "Cheat DLL injected successfully into csgo.exe." << endl;
        }
        else {
            cout << "Failed to inject Cheat DLL into csgo.exe." << endl;
        }
    }
    else {
        cout << "csgo.exe process not found. Exiting." << endl;
        return 1;
    }

    break;
}