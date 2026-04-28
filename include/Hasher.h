#pragma once
#include <string>

class Hasher {
public:
    // Calculate the SHA-256 hash of a given file natively on macOS (High Sierra to Tahoe)
    static std::string calculateSHA256(const std::string& filePath);
};