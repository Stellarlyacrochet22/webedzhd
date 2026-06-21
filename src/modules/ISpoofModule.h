#pragma once

#include <string>

class ISpoofModule {
public:
    virtual ~ISpoofModule() = default;
    virtual std::string name() const = 0;
    virtual bool readCurrent(std::string& out) = 0;
    virtual bool apply(const std::string& value) = 0;
    virtual bool restore(const std::string& original) = 0;
};
