#include "ISpoofModule.h"
#include <memory>
#include <random>
#include <sstream>
#include <iomanip>

class DiskSerialSpoofer : public ISpoofModule {
public:
    std::string name() const override { return "disk"; }

    bool readCurrent(std::string& out) override {
        out = current_.empty() ? "READ_DISK_SERIAL" : current_;
        return true;
    }

    bool apply(const std::string& value) override {
        if (value == "RANDOM") {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> dist(0, 15);
            std::ostringstream ss;
            for (int i = 0; i < 20; ++i) ss << std::hex << dist(gen);
            current_ = ss.str();
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

std::unique_ptr<ISpoofModule> createDiskSerialSpoofer() {
    return std::make_unique<DiskSerialSpoofer>();
}
