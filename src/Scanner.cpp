#include "Scanner.h"
#include "Hasher.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

Scanner::Scanner(const std::string& qDir) : quarantineManager(qDir) {
    // Load dummy signatures for testing purposes
    // "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855" is the hash for an empty text file
    virusSignatures.insert("e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");
}

void Scanner::scanDirectory(const std::string& targetDir) {
    std::cout << "--- INITIATING SYSTEM SCAN: " << targetDir << " ---\n";
    
    for (const auto& entry : fs::recursive_directory_iterator(targetDir)) {
        try {
            if (entry.is_regular_file()) {
                std::string currentFile = entry.path().string();

                // Utilize the static method from the Hasher class
                std::string fileHash = Hasher::calculateSHA256(currentFile);

                if (virusSignatures.find(fileHash) != virusSignatures.end()) {
                    std::cout << "\n[ALERT] THREAT DETECTED!" << std::endl;
                    std::cout << "File: " << currentFile << std::endl;
                    std::cout << "Signature: " << fileHash << std::endl;

                    // Delegate the isolation task to the Quarantine module
                    quarantineManager.isolateFile(currentFile);
                }
            }
        } catch (const fs::filesystem_error& e) {
            // Bypass files PROTECTED by the OS.
            continue;
        }
    }
    std::cout << "--- SCAN COMPLETED ---\n";
}