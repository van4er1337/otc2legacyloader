#include "includes.h"
#include "registerandlogin.h"
using namespace std;

bool injectdll(DWORD processId, const std::wstring& dllPath) {
    // ��������� ������� �������
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
    if (hProcess == NULL) {
        wcerr << L"Failed to open the target process. Error code: " << GetLastError() << endl;
        return false;
    }

    // ���������� ������ � �������� ��� ���� � DLL
    LPVOID remoteString = VirtualAllocEx(hProcess, NULL, (dllPath.size() + 1) * sizeof(wchar_t), MEM_COMMIT, PAGE_READWRITE);
    if (remoteString == NULL) {
        wcerr << L"Failed to allocate memory in the target process. Error code: " << GetLastError() << endl;
        CloseHandle(hProcess);
        return false;
    }

    // ���������� ���� � DLL � ������ ��������
    if (!WriteProcessMemory(hProcess, remoteString, dllPath.c_str(), (dllPath.size() + 1) * sizeof(wchar_t), NULL)) {
        wcerr << L"Failed to write to the target process memory. Error code: " << GetLastError() << endl;
        CloseHandle(hProcess);
        VirtualFreeEx(hProcess, remoteString, 0, MEM_RELEASE);
        return false;
    }

    // �������� ����� LoadLibraryW
    LPVOID loadLibraryAddr = GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "LoadLibraryW");
    HMODULE hKernel32 = GetModuleHandleW(L"kernel32.dll");
    if (hKernel32 == NULL) {
        if (loadLibraryAddr == NULL) {
            wcerr << L"Failed to get the address of LoadLibraryW function. Error code: " << GetLastError() << endl;
            CloseHandle(hProcess);
            // �������������� ��������, ���� ����������
            return false;
        }
    }

    // ������� ��������� ����� ��� ������ LoadLibraryW � ����� � DLL � �������� ���������
    HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)loadLibraryAddr, remoteString, 0, NULL);
    if (hThread == NULL) {
        wcerr << L"Failed to create a remote thread in the target process. Error code: " << GetLastError() << endl;
        CloseHandle(hProcess);
        VirtualFreeEx(hProcess, remoteString, 0, MEM_RELEASE);
        return false;
    }

    // ������� ���������� ������
    WaitForSingleObject(hThread, INFINITE);

    // ��������� ����������� � ����������� ������
    CloseHandle(hThread);
    CloseHandle(hProcess);
    VirtualFreeEx(hProcess, remoteString, 0, MEM_RELEASE);

    return true;
}

