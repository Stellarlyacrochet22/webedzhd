#include "ISpoofModule.h"
#include <memory>
#include <random>
#include <cstdio>

class VolumeSerialSpoofer : public ISpoofModule {
public:
    std::string name() const override { return "volume"; }

    bool readCurrent(std::string& out) override {
        out = current_.empty() ? "0000-0000" : current_;
        return true;
    }

    bool apply(const std::string& value) override {
        if (value == "RANDOM") {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> dist(0, 65535);
            char buf[16];
            snprintf(buf, sizeof(buf), "%04X-%04X", dist(gen), dist(gen));
            current_ = buf;
        } else {
            current_ = value;
        }
        return true;
    }

    bool restore(const std::string& original) override {
        current_ = original;
        return true;
    }

private:
    std::string current_;
};

std::unique_ptr<ISpoofModule> createVolumeSerialSpoofer() {
    return std::make_unique<VolumeSerialSpoofer>();
}
