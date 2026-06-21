#include "HwidReader.h"

namespace hwid {

HwidSnapshot HwidReader::capture() {
    HwidSnapshot snap;
    snap.timestamp = "captured";
    snap.diskSerial = "UNKNOWN";
    snap.smbiosUuid = "UNKNOWN";
    return snap;
}

} // namespace hwid
