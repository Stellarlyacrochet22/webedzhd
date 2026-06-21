#include "BackupManager.h"
#include <fstream>

namespace hwid {

BackupManager::BackupManager(std::string path) : path_(std::move(path)) {}

bool BackupManager::save(const HwidSnapshot& snapshot) {
    std::ofstream out(path_, std::ios::trunc);
    if (!out) return false;
    out << "{\n";
    out << "  \"timestamp\": \"" << snapshot.timestamp << "\",\n";
    out << "  \"disk_serial\": \"" << snapshot.diskSerial << "\",\n";
    out << "  \"smbios_uuid\": \"" << snapshot.smbiosUuid << "\"\n";
    out << "}\n";
    return true;
}

bool BackupManager::load(HwidSnapshot& snapshot) const {
    std::ifstream in(path_);
    if (!in) return false;
    // Minimal stub — full JSON parser in production build
    snapshot.timestamp = "loaded";
    return true;
}

bool BackupManager::exists() const {
    std::ifstream in(path_);
    return in.good();
}

} // namespace hwid
