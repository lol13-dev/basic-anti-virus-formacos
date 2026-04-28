# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(BasicAntivirus VERSION 1.0)

# Specify the C++ Standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory so the complier can find the headers
include_directories(include)

# Create the executable from the source files
add_executable (MacAV
    src/main.cpp
    src/Hasher.cpp
    src/Quarantine.cpp
    src/Scanner.cpp
)