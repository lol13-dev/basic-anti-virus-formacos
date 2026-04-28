# 🛡️ macOS Native Antivirus Engine (C++)

A lightweight, modular Endpoint Detection and Response (EDR) simulator built natively for macOS. This project demonstrates core cybersecurity concepts, including signature-based threat detection, file integrity monitoring, and interactive threat remediation using modern C++17.

## ✨ Key Features

* **Native Cryptography:** Utilizes Apple's native `<CommonCrypto/CommonDigest.h>` for highly optimized SHA-256 hashing, eliminating the need for bulky external libraries.
* **Memory Efficient:** Processes large files in 8KB memory chunks, preventing RAM exhaustion during deep system scans.
* **Interactive CLI Engine:** Features a real-time progress indicator and an interactive decision engine (Quarantine, Delete, or Ignore) upon threat detection.
* **Privilege Stripping:** When isolating a threat, the engine automatically modifies UNIX file permissions, removing execution rights to neutralize malicious payloads.
* **SIP Exception Handling:** Safely bypasses macOS System Integrity Protection (SIP) locked directories without crashing the main thread.

## 🏗️ Architecture

The project follows a strict Separation of Concerns (SoC) modular architecture:
* `Hasher`: Handles all cryptographic operations.
* `Quarantine`: Manages threat isolation, file deletion, and permission stripping.
* `Scanner`: Orchestrates recursive directory traversal and signature matching.

## ⚙️ Prerequisites

To compile and run this engine, you must be on a macOS environment with the following installed:
* **C++ Compiler:** Clang (Apple LLVM) with C++17 support.
* **Build System:** [CMake](https://cmake.org/) (v3.10 or higher).

## 🚀 Build & Installation

This project uses CMake for build automation. Clone the repository and compile the source code using the following commands:

```bash
# 1. Clone the repository
git clone [https://github.com/lol13-dev/basic-anti-virus-formacos.git](https://github.com/lol13-dev/basic-anti-virus-formacos.git)
cd basic-anti-virus-formacos

# 2. Create a build directory
mkdir build
cd build

# 3. Generate Makefiles and compile
cmake ..
make
