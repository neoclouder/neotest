add_library(${NEOTEST_NAME} neotest.c)

neo_enable_lto(${NEOTEST_NAME})
neo_set_warnings(${NEOTEST_NAME})
neo_add_coverage(${NEOTEST_NAME})
neo_add_sanitizers(${NEOTEST_NAME})
