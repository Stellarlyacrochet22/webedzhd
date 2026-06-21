#include "SpoofEngine.h"
#include "Logger.h"

namespace hwid {

SpoofEngine::SpoofEngine() = default;

void SpoofEngine::registerModule(std::unique_ptr<ISpoofModule> module) {
    modules_.push_back(std::move(module));
}

bool SpoofEngine::runStatus() const {
    for (const auto& mod : modules_) {
        std::string current;
        mod->readCurrent(current);
        Logger::log(LogLevel::Info, mod->name() + ": " + current);
    }
    return true;
}

bool SpoofEngine::runBackup(BackupManager& backup) {
    HwidSnapshot snap;
    snap.timestamp = "now";
    for (const auto& mod : modules_) {
        std::string val;
        mod->readCurrent(val);
        if (mod->name() == "disk") snap.diskSerial = val;
        if (mod->name() == "smbios") snap.smbiosUuid = val;
    }
    return backup.save(snap);
}

bool SpoofEngine::runSpoofAll() {
    for (auto& mod : modules_) {
        Logger::log(LogLevel::Info, "Spoofing: " + mod->name());
        mod->apply("RANDOM");
    }
    return true;
}

bool SpoofEngine::runRestore(BackupManager& backup) {
    HwidSnapshot snap;
    if (!backup.load(snap)) return false;
    for (auto& mod : modules_) {
        if (mod->name() == "disk") mod->restore(snap.diskSerial);
        if (mod->name() == "smbios") mod->restore(snap.smbiosUuid);
    }
    return true;
}

} // namespace hwid
