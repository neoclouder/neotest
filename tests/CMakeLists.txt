

# --- OK
add_executable(test_neotest_ok test_neotest_ok.c)
target_link_libraries(test_neotest_ok PRIVATE ${NEOTEST_NAME})

neo_set_warnings(test_neotest_ok)
neo_add_coverage(test_neotest_ok)
neo_add_sanitizers(test_neotest_ok)

add_test(NAME test_neotest_ok COMMAND test_neotest_ok)

# --- KO
add_executable(test_neotest_ko test_neotest_ko.c)
target_link_libraries(test_neotest_ko PRIVATE ${NEOTEST_NAME})

neo_set_warnings(test_neotest_ko)
neo_add_coverage(test_neotest_ko)
neo_add_sanitizers(test_neotest_ko)

add_test(NAME test_neotest_ko COMMAND test_neotest_ko)

set_tests_properties(test_neotest_ko PROPERTIES WILL_FAIL true)

# --- Coverage reports
#set(TEST_TARGETS test_neotest_ok test_neotest_ko)
#neo_enable_coverage_reports(${TEST_TARGETS})
