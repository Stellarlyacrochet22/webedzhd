#pragma once

#include "BackupManager.h"

namespace hwid {

class HwidReader {
public:
    static HwidSnapshot capture();
};

} // namespace hwid
