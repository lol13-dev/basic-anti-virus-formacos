#include "Hasher.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <CommonCrypto/CommonDigest.h>

std::string Hasher::calculateSHA256(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) return "";

    CC_SHA256_CTX sha256Context;
    CC_SHA256_Init(&sha256Context);

    char buffer[8192]; // 8KB buffer for efficient memory usage
    while (file.read(buffer, sizeof(buffer))) {
        CC_SHA256_Update(&sha256Context, buffer, file.gcount());
    }
    CC_SHA256_Update(&sha256Context, buffer, file.gcount());

    unsigned char hash[CC_SHA256_DIGEST_LENGTH];
    CC_SHA256_Final(hash, &sha256Context);

    std::stringstream ss;
    for (int i = 0; i < CC_SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}