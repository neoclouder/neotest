/**
 * @brief A testing framework for C.
 *
 * @author Yohan Beschi
 * @date 23/06/2024
 */

#ifndef NEOTEST_NEOTEST_H
#define NEOTEST_NEOTEST_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    const char *name;
    void (*test_function)(void);
} tst_TestCase;

/**
 * @brief Runs multiple test cases.
 *
 * @param test_cases Array of tst_TestCase structures.
 * @param num_tests Number of test cases in the array.
 * @return Returns 0 if all tests pass, otherwise returns the number of failed tests.
 */
int tst_run_tests(const tst_TestCase test_cases[], int num_tests);

/**
 * @brief Forces a test to fail.
 *
 * @param error_message Error message to display on failure.
 */
void tst_fail(const char *error_message);

/**
 * @brief Prints a success message.
 *
 * @param message Message to display on success.
 */
void tst_succeed(const char *message);

/**
 * @brief Asserts that a boolean condition is true.
 *
 * @param error_message Error message to display if assertion fails.
 * @param comparison_result Boolean result of the comparison.
 */
void tst_assert_true(const char *error_message, bool comparison_result);

/**
 * @brief Asserts that a boolean condition is false.
 *
 * @param error_message Error message to display if assertion fails.
 * @param comparison_result Boolean result of the comparison.
 */
void tst_assert_false(const char *error_message, bool comparison_result);

/**
 * @brief Asserts that two characters are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected character value.
 * @param actual Actual character value.
 */
void tst_assert_char(const char *error_message, char expected, char actual);

/**
 * @brief Asserts that two signed characters are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected signed character value.
 * @param actual Actual signed character value.
 */
void tst_assert_schar(const char *error_message, signed char expected, signed char actual);

/**
 * @brief Asserts that two unsigned characters are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected unsigned character value.
 * @param actual Actual unsigned character value.
 */
void tst_assert_uchar(const char *error_message, unsigned char expected, unsigned char actual);

/**
 * @brief Asserts that two short integers are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected short integer value.
 * @param actual Actual short integer value.
 */
void tst_assert_short(const char *error_message, short expected, short actual);

/**
 * @brief Asserts that two integers are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected integer value.
 * @param actual Actual integer value.
 */
void tst_assert_int(const char *error_message, int expected, int actual);

/**
 * @brief Asserts that two long integers are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected long integer value.
 * @param actual Actual long integer value.
 */
void tst_assert_long(const char *error_message, long expected, long actual);

/**
 * @brief Asserts that two long long integers are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected long long integer value.
 * @param actual Actual long long integer value.
 */
void tst_assert_long_long(const char *error_message, long long expected, long long actual);

/**
 * @brief Asserts that two unsigned short integers are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected unsigned short integer value.
 * @param actual Actual unsigned short integer value.
 */
void tst_assert_ushort(const char *error_message, unsigned short expected, unsigned short actual);

/**
 * @brief Asserts that two unsigned integers are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected unsigned integer value.
 * @param actual Actual unsigned integer value.
 */
void tst_assert_uint(const char *error_message, unsigned int expected, unsigned int actual);

/**
 * @brief Asserts that two unsigned long integers are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected unsigned long integer value.
 * @param actual Actual unsigned long integer value.
 */
void tst_assert_ulong(const char *error_message, unsigned long expected, unsigned long actual);

/**
 * @brief Asserts that two unsigned long long integers are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected unsigned long long integer value.
 * @param actual Actual unsigned long long integer value.
 */
void tst_assert_ulong_long(const char *error_message, unsigned long long expected, unsigned long long actual);

/**
 * @brief Asserts that two floating point numbers are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected float value.
 * @param actual Actual float value.
 */
void tst_assert_float(const char *error_message, float expected, float actual);

/**
 * @brief Asserts that two double precision floating point numbers are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected double value.
 * @param actual Actual double value.
 */
void tst_assert_double(const char *error_message, double expected, double actual);

/**
 * @brief Asserts that two long double precision floating point numbers are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected long double value.
 * @param actual Actual long double value.
 */
void tst_assert_long_double(const char *error_message, long double expected, long double actual);

/**
 * @brief Asserts that two strings are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected string.
 * @param actual Actual string.
 */
void tst_assert_str(const char *error_message, char *expected, char *actual);

/**
 * @brief Asserts that two int8_t values are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected int8_t value.
 * @param actual Actual int8_t value.
 */
void tst_assert_int8(const char *error_message, int8_t expected, int8_t actual);

/**
 * @brief Asserts that two int16_t values are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected int16_t value.
 * @param actual Actual int16_t value.
 */
void tst_assert_int16(const char *error_message, int16_t expected, int16_t actual);

/**
 * @brief Asserts that two int32_t values are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected int32_t value.
 * @param actual Actual int32_t value.
 */
void tst_assert_int32(const char *error_message, int32_t expected, int32_t actual);

/**
 * @brief Asserts that two int64_t values are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected int64_t value.
 * @param actual Actual int64_t value.
 */
void tst_assert_int64(const char *error_message, int64_t expected, int64_t actual);

/**
 * @brief Asserts that two uint8_t values are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected uint8_t value.
 * @param actual Actual uint8_t value.
 */
void tst_assert_uint8(const char *error_message, uint8_t expected, uint8_t actual);

/**
 * @brief Asserts that two uint16_t values are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected uint16_t value.
 * @param actual Actual uint16_t value.
 */
void tst_assert_uint16(const char *error_message, uint16_t expected, uint16_t actual);

/**
 * @brief Asserts that two uint32_t values are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected uint32_t value.
 * @param actual Actual uint32_t value.
 */
void tst_assert_uint32(const char *error_message, uint32_t expected, uint32_t actual);

/**
 * @brief Asserts that two uint64_t values are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected uint64_t value.
 * @param actual Actual uint64_t value.
 */
void tst_assert_uint64(const char *error_message, uint64_t expected, uint64_t actual);

/**
 * @brief Asserts that two size_t values are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected size_t value.
 * @param actual Actual size_t value.
 */
void tst_assert_size(const char *error_message, size_t expected, size_t actual);

/**
 * @brief Asserts that two intptr_t values are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected intptr_t value.
 * @param actual Actual intptr_t value.
 */
void tst_assert_intptr(const char *error_message, intptr_t expected, intptr_t actual);

/**
 * @brief Asserts that two uintptr_t values are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected uintptr_t value.
 * @param actual Actual uintptr_t value.
 */
void tst_assert_uintptr(const char *error_message, uintptr_t expected, uintptr_t actual);

/**
 * @brief Asserts that two ptrdiff_t values are equal.
 *
 * @param error_message Error message to display if assertion fails.
 * @param expected Expected ptrdiff_t value.
 * @param actual Actual ptrdiff_t value.
 */
void tst_assert_ptrdiff(const char *error_message, ptrdiff_t expected, ptrdiff_t actual);

#endif /* NEOTEST_NEOTEST_H */
