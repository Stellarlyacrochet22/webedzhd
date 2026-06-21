# Build Guide

## Prerequisites

- Windows 10/11 x64
- [Visual Studio 2022](https://visualstudio.microsoft.com/) with:
  - Desktop development with C++
  - Windows 10/11 SDK (10.0.22621 or newer)
- [CMake 3.20+](https://cmake.org/download/)
- *(Optional)* [Windows Driver Kit (WDK)](https://learn.microsoft.com/en-us/windows-hardware/drivers/download-the-wdk) for `driver/`

## Standard Build (user-mode only)

```powershell
git clone https://github.com/your-username/hwid-spoofer.git
cd hwid-spoofer

cmake -B build -G "Visual Studio 17 2022" -A x64 -DHWID_NO_DRIVER=ON
cmake --build build --config Release
```

Binary: `build\Release\HWIDSpoofer.exe`

## Build with Driver

```powershell
cmake -B build -G "Visual Studio 17 2022" -A x64 -DHWID_BUILD_DRIVER=ON
cmake --build build --config Release
```

Enable test signing for local driver load:

```powershell
bcdedit /set testsigning on
# reboot
```

## CMake Options

| Option | Default | Description |
|--------|---------|-------------|
| `HWID_NO_DRIVER` | OFF | Skip kernel driver |
| `HWID_BUILD_GUI` | ON | Build Win32 GUI alongside CLI |
| `HWID_BUILD_DRIVER` | OFF | Build WDK driver target |

## Troubleshooting

**LNK1104 cannot open file** — Close running `HWIDSpoofer.exe` before rebuild.

**Access denied on spoof** — Run terminal as Administrator.

**SmartScreen blocks EXE** — Unsigned build. Sign with your cert or build locally.
