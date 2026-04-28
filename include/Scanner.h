#pragma once
#include <string>
#include <unordered_set>
#include "Quarantine.h"

class Scanner {
private:
    std::unordered_set<std::string> virusSignatures;
    Quarantine quarantineManager;

public:
    // Initializes the scanner with the targeet quarantine directory
    Scanner(const std::string& qDir);

    // Initiates the recursive scanning process
    void scanDirectory(const std::string& targetDir);
};