#include "Scanner.h"
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

int main(){
    std::string quarantineLocation = "./MAC_QUARANTINE";
    std::string targetLocation = "./TEST_ZONE";

    // Setup the sandbox environment for safe testing.
    if (!fs::exists(targetLocation)) {
        fs::create_directory(targetLocation);
    }

    // CREATE an empty dummy file to trigger the signature match.
    std::ofstream dummyFile(targetLocation + "/malicious_dummy.txt");
    dummyFile.close();

    // Instantiate and RUN the scanner engine.
    Scanner avEngine(quarantineLocation);
    avEngine.scanDirectory(targetLocation);

    return 0;
}