#include <windows.h>

int WINAPI wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int) {
    MessageBoxW(nullptr,
        L"HWID Spoofer GUI — use CLI for full functionality.\n"
        L"Run: HWIDSpoofer.exe status",
        L"HWID Spoofer",
        MB_OK | MB_ICONINFORMATION);
    return 0;
}
