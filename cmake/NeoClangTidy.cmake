if(NEOTEST_STANDALONE AND NEOTEST_ENABLE_CLANG_TIDY)
  # find clang-tidy program
  find_program(
    CLANG_TIDY_EXE
    NAMES "clang-tidy"
    DOC "Path to clang-tidy executable")

  if(NOT CLANG_TIDY_EXE)
    message(STATUS "clang-tidy not found.")
  else()
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
    # and assemble command to be run through CXX_CLANG_TIDY target property
    set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}")
    set(CMAKE_C_CLANG_TIDY "clang-tidy")
  endif()
else()
  message(STATUS "clang-tidy disabled")
endif()
