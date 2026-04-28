#pragma once
#include <string>

class Quarantine {
private:
    std::string quarantineDir;

public:
    // Constructor to initialize the quarantine zone.
    Quarantine(const std::string& qDir);

    // Isolates the detected threat.
    void isolateFile(const std::string& filePath);
};