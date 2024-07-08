add_library(${NEOTEST_NAME} neotest.c)

target_include_directories(${NEOTEST_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>)

neo_enable_lto(${NEOTEST_NAME})
neo_set_warnings(${NEOTEST_NAME})
neo_add_coverage(${NEOTEST_NAME})
neo_add_sanitizers(${NEOTEST_NAME})
