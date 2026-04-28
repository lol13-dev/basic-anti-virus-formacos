#include "Quarantine.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

Quarantine::Quarantine(const std::string& qDir) : quarantineDir(qDir) {
    // Ensure the quaratine directory exists upon installation
    if (!fs::exists(quarantineDir)) {
        fs::create_directory(quarantineDir);
    }
}

void Quarantine::isolateFile(const std::string& filePath) {
    try {
        std::string fileName = fs::path(filePath).filename().string();
        std::string destination = quarantineDir + "/" + fileName + ".quarantined";

        // Move the file to the secure location
        fs::rename(filePath, destination);

        // Strip executable permissions to neutralize the THREAT.
        fs::permissions(destination, fs::perms::owner_read | fs::perms::owner_write, fs::perm_options::replace);

        std::cout << "[ACTION] File successfully quarantined: " << destination << std::endl;


    } catch (const fs::filesystem_error& e) {
        std::cerr << "[ERROR] Quarantine failed: " << e.what() << std::endl;
    }
}