#include "modules/ISpoofModule.h"
#include "core/Logger.h"
#include "core/BackupManager.h"
#include "core/SpoofEngine.h"
#include <iostream>
#include <string>
#include <memory>

extern std::unique_ptr<ISpoofModule> createDiskSerialSpoofer();
extern std::unique_ptr<ISpoofModule> createSmbiosSpoofer();
extern std::unique_ptr<ISpoofModule> createMacSpoofer();
extern std::unique_ptr<ISpoofModule> createVolumeSerialSpoofer();
extern std::unique_ptr<ISpoofModule> createRegistryCleaner();

static void printHelp() {
    std::cout <<
        "HWID Spoofer v1.0.0\n\n"
        "Usage: HWIDSpoofer.exe [command] [options]\n\n"
        "Commands:\n"
        "  status          Show current hardware identifiers\n"
        "  backup          Save snapshot to backup/hwid_backup.json\n"
        "  restore         Restore from last backup\n"
        "  spoof --all     Apply all enabled spoof modules\n"
        "  clean           Remove common fingerprint registry keys\n"
        "  help            Show this help\n";
}

int main(int argc, char* argv[]) {
    hwid::Logger::init();

    if (argc < 2) {
        printHelp();
        return 0;
    }

    hwid::SpoofEngine engine;
    engine.registerModule(createDiskSerialSpoofer());
    engine.registerModule(createSmbiosSpoofer());
    engine.registerModule(createMacSpoofer());
    engine.registerModule(createVolumeSerialSpoofer());
    engine.registerModule(createRegistryCleaner());

    hwid::BackupManager backup("backup/hwid_backup.json");
    std::string cmd = argv[1];

    if (cmd == "status") return engine.runStatus() ? 0 : 1;
    if (cmd == "backup") return engine.runBackup(backup) ? 0 : 1;
    if (cmd == "restore") return engine.runRestore(backup) ? 0 : 1;
    if (cmd == "spoof" && argc > 2 && std::string(argv[2]) == "--all")
        return engine.runSpoofAll() ? 0 : 1;
    if (cmd == "clean") {
        hwid::Logger::log(hwid::LogLevel::Info, "Registry clean stub executed");
        return 0;
    }
    if (cmd == "help" || cmd == "--help") {
        printHelp();
        return 0;
    }

    hwid::Logger::log(hwid::LogLevel::Error, "Unknown command: " + cmd);
    printHelp();
    return 1;
}
