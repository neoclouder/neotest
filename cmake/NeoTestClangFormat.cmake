if(NEOTEST_STANDALONE AND NEOTEST_ENABLE_CLANG_FORMAT)
  # find clang-format executable
  find_program(
    CLANG_FORMAT_EXE
    NAMES "clang-format"
    DOC "Path to clang-format executable")

  # add custom target if found
  if(CLANG_FORMAT_EXE)
    message(STATUS "clang-format found: ${CLANG_FORMAT_EXE}")

    # get all sources
    file(
      GLOB_RECURSE
      ALL_SOURCES
      "src/*.c"
      "src/*.h"
      "tests/*.c"
      "tests/*.h"
      "include/**/*.h")

    add_custom_target(${NEOTEST_NAME}-clang-format ALL COMMAND ${CLANG_FORMAT_EXE} -style=file -i
                                           ${ALL_SOURCES})
    add_custom_target(${NEOTEST_NAME}-clang-format-check ALL COMMAND ${CLANG_FORMAT_EXE}
                        -style=file
                        --dry-run
                        --Werror
                        -i ${ALL_SOURCES})
  else()
    message(STATUS "clang-format not found.")
  endif()
else()
  message(STATUS "clang-format disabled")
endif()