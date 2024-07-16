# Find coverage tools
find_program(GCOV_BIN gcov)
find_program(LCOV_BIN lcov)
find_program(GENHTML_BIN genhtml)

if (NOT GCOV_BIN OR NOT LCOV_BIN OR NOT GENHTML_BIN)
    set(COVERAGE_BIN 0)
    message(WARNING "Coverage tools not found! Coverage reporting will be disabled.")
else()
    set(COVERAGE_BIN 1)
endif()

# Function to add coverage instrumentation to a target
function(neo_add_coverage target)
    if(NEOTEST_STANDALONE AND NEOTEST_ENABLE_COVERAGE)
        find_program(LCOV_EXECUTABLE lcov)
        find_program(GCOV_EXECUTABLE gcov)
        find_program(GENHTML_EXECUTABLE genhtml)

        if(NOT LCOV_EXECUTABLE)
            message(FATAL_ERROR "lcov not found! Please install lcov.")
        endif()

        if(NOT GCOV_EXECUTABLE)
            message(FATAL_ERROR "gcov not found! Please install gcov.")
        endif()

        if(NOT GENHTML_EXECUTABLE)
            message(FATAL_ERROR "genhtml not found! Please install genhtml.")
        endif()

        if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
            message(STATUS "Enabling Coverage for target: ${target}")

            # Add compiler flags for coverage instrumentation
            target_compile_options(${target} PRIVATE --coverage)
            target_link_options(${target} PRIVATE --coverage)
        else()
            message(WARNING "Coverage is only supported for GNU GCC and Clang compilers.")
        endif()
    endif()
endfunction()

#function(neo_enable_coverage_reports targets)
#    if(NEOTEST_STANDALONE AND NEOTEST_ENABLE_COVERAGE)
#        message(STATUS "Generating Coverage reports...")
#
#        # Variables for commands
#        set(LCOV_OUTPUT_FILE ${CMAKE_BINARY_DIR}/coverage.info)
#        set(GENHTML_OUTPUT_DIR ${CMAKE_BINARY_DIR}/coverage)
#
#        # Combined custom target 'coverage-report' with test execution and coverage reporting
#        add_custom_target(coverage-report ALL
#                COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
#                COMMAND ${LCOV_EXECUTABLE} --capture --directory ${CMAKE_BINARY_DIR} --output-file ${LCOV_OUTPUT_FILE} --rc branch_coverage=1
#                COMMAND ${LCOV_EXECUTABLE} --remove ${LCOV_OUTPUT_FILE} '*/tests/*' --output-file ${LCOV_OUTPUT_FILE}
#                COMMAND ${LCOV_EXECUTABLE} --list ${LCOV_OUTPUT_FILE}
#                COMMAND ${GENHTML_EXECUTABLE} ${LCOV_OUTPUT_FILE} --output-directory ${GENHTML_OUTPUT_DIR}
#                DEPENDS ${targets}
#                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#                COMMENT "Running tests and generating coverage report"
#        )
#    endif()
#endfunction()
