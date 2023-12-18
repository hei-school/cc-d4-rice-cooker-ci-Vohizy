cmake_minimum_required(VERSION 3.10)
project(RiceCookerProject)

# Locate GTest
find_package(GTest REQUIRED)

# Include headers
include_directories(include)

# Add the source files
set(SOURCE_FILES
    src/RiceCooker.cpp
    tests/RiceCookerTest.cpp
)

# Create the executable
add_executable(RiceCookerTest ${SOURCE_FILES})

# Link against GTest and pthread library
target_link_libraries(RiceCookerTest GTest::GTest GTest::Main pthread)
