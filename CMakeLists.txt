cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(neotest VERSION 0.1.0 LANGUAGES C)
set(NEOTEST_NAME neotest)

# Ensure C99 standard and disable compiler extensions
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

string(COMPARE EQUAL "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}" NEOTEST_STANDALONE)

# Options
option(NEOTEST_ENABLE_WARNINGS     "Add warnings to a target"             OFF)
option(NEOTEST_BUILD_TESTS         "Build Unit Tests"                     OFF)
option(NEOTEST_BUILD_EXAMPLES      "Build the examples"                   OFF)
option(NEOTEST_ENABLE_COVERAGE     "Enable Code Coverage"                 OFF)
option(NEOTEST_ENABLE_CLANG_TIDY   "Enable clang-tidy. (static analysis)" OFF)
option(NEOTEST_ENABLE_CLANG_FORMAT "Enable clang-format. (formatting)"    OFF)
option(NEOTEST_BUILD_DOC           "Build the documentation"              OFF)
option(NEOTEST_ENABLE_SANITIZERS   "Enable sanitizers"                    OFF)

# Messages
message(STATUS "NEOTEST_STANDALONE:          ${NEOTEST_STANDALONE}")
message(STATUS "NEOTEST_ENABLE_WARNINGS:     ${NEOTEST_ENABLE_WARNINGS}")
message(STATUS "NEOTEST_BUILD_TESTS:         ${NEOTEST_BUILD_TESTS}")
message(STATUS "NEOTEST_ENABLE_COVERAGE:     ${NEOTEST_ENABLE_COVERAGE}")
message(STATUS "NEOTEST_ENABLE_CLANG_TIDY:   ${NEOTEST_ENABLE_CLANG_TIDY}")
message(STATUS "NEOTEST_ENABLE_CLANG_FORMAT: ${NEOTEST_ENABLE_CLANG_FORMAT}")
message(STATUS "NEOTEST_BUILD_DOC:           ${NEOTEST_BUILD_DOC}")
message(STATUS "NEOTEST_ENABLE_SANITIZERS:   ${NEOTEST_ENABLE_SANITIZERS}")

# --- CMake Modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
message(STATUS "NEOTEST_CMAKE_CURRENT_SOURCE_DIR:   ${CMAKE_CURRENT_SOURCE_DIR}")

include(NeoTest)

# --- Library
add_subdirectory(src)

if(NEOTEST_BUILD_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()
