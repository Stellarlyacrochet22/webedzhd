#pragma once

#include "BackupManager.h"
#include <memory>
#include <vector>
#include "modules/ISpoofModule.h"

namespace hwid {

class SpoofEngine {
public:
    SpoofEngine();

    void registerModule(std::unique_ptr<ISpoofModule> module);
    bool runStatus() const;
    bool runBackup(BackupManager& backup);
    bool runSpoofAll();
    bool runRestore(BackupManager& backup);

private:
    std::vector<std::unique_ptr<ISpoofModule>> modules_;
};

} // namespace hwid
