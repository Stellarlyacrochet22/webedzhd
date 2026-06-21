#include "ISpoofModule.h"
#include <memory>

class RegistryCleaner : public ISpoofModule {
public:
    std::string name() const override { return "registry"; }

    bool readCurrent(std::string& out) override {
        out = "registry_fingerprint_keys";
        return true;
    }

    bool apply(const std::string&) override { return true; }
    bool restore(const std::string&) override { return true; }
};

std::unique_ptr<ISpoofModule> createRegistryCleaner() {
    return std::make_unique<RegistryCleaner>();
}
