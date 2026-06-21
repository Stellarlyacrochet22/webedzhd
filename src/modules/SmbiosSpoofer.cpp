#include "ISpoofModule.h"
#include <memory>

class SmbiosSpoofer : public ISpoofModule {
public:
    std::string name() const override { return "smbios"; }

    bool readCurrent(std::string& out) override {
        out = current_.empty() ? "READ_SMBIOS_UUID" : current_;
        return true;
    }

    bool apply(const std::string& value) override {
        current_ = value == "RANDOM" ? "00000000-0000-4000-8000-000000000001" : value;
        return true;
    }

    bool restore(const std::string& original) override {
        current_ = original;
        return true;
    }

private:
    std::string current_;
};

std::unique_ptr<ISpoofModule> createSmbiosSpoofer() {
    return std::make_unique<SmbiosSpoofer>();
}
