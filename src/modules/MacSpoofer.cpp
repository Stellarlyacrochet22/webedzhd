#include "ISpoofModule.h"
#include <memory>
#include <random>
#include <sstream>
#include <iomanip>

class MacSpoofer : public ISpoofModule {
public:
    std::string name() const override { return "mac"; }

    bool readCurrent(std::string& out) override {
        out = current_.empty() ? "00:00:00:00:00:00" : current_;
        return true;
    }

    bool apply(const std::string& value) override {
        if (value == "RANDOM") {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> dist(0, 255);
            std::ostringstream ss;
            for (int i = 0; i < 6; ++i) {
                if (i) ss << ':';
                ss << std::hex << std::setw(2) << std::setfill('0') << dist(gen);
            }
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

std::unique_ptr<ISpoofModule> createMacSpoofer() {
    return std::make_unique<MacSpoofer>();
}
