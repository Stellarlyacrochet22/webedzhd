# Contributing to HWID Spoofer

Thank you for your interest in contributing.

## Getting Started

1. Fork the repository
2. Clone your fork locally
3. Create a feature branch from `main`
4. Build and test on Windows 10/11 x64

## Development Setup

```powershell
cmake -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Release
.\build\Release\HWIDSpoofer.exe status
```

## Code Style

- C++17, MSVC-compatible
- 4-space indentation, no tabs
- PascalCase for classes, camelCase for functions and variables
- One class per file under `src/modules/`
- Log via `core/Logger.h` — no raw `printf` in library code

## Pull Request Guidelines

- Keep PRs focused — one module or fix per PR
- Update `docs/` if you add or change behavior
- Do not commit binaries, `.env` files, or personal backup JSON
- Describe testing performed (OS version, admin/non-admin, modules touched)

## Reporting Issues

Use the issue templates. Include:

- Windows version and build
- Admin elevation yes/no
- Full command line and output
- Relevant log excerpt from `%TEMP%\hwid-spoofer.log`

## Code of Conduct

Be respectful. Harassment and spam will not be tolerated.
