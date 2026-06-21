#pragma once

#include <string>
#include <vector>
#include <memory>
#include "modules/ISpoofModule.h"

namespace hwid {

struct HwidSnapshot {
    std::string timestamp;
    std::string diskSerial;
    std::string smbiosUuid;
    std::vector<std::string> macAddresses;
    std::vector<std::string> volumeSerials;
};

class BackupManager {
public:
    explicit BackupManager(std::string path);

    bool save(const HwidSnapshot& snapshot);
    bool load(HwidSnapshot& snapshot) const;
    bool exists() const;

private:
    std::string path_;
};

} // namespace hwid
