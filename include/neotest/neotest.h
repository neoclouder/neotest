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
 * @param message Error message to display on failure.
 */
void tst_fail(const char *message);

/**
 * @brief Prints a success message.
 *
 * @param message Message to display on success.
 */
void tst_succeed(const char *message);

/**
 * @brief Asserts that a boolean condition is true.
 *
 * @param message Error message to display if assertion fails.
 * @param comparison_result Boolean result of the comparison.
 */
void tst_assert_true(const char *message, const bool comparison_result);

/**
 * @brief Asserts that a boolean condition is false.
 *
 * @param message Error message to display if assertion fails.
 * @param comparison_result Boolean result of the comparison.
 */
void tst_assert_false(const char *message, const bool comparison_result);

/**
 * @brief Asserts that two characters are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected character value.
 * @param actual Actual character value.
 */
void tst_assert_char(const char *message, const char expected, const char actual);

/**
 * @brief Asserts that two signed characters are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected signed character value.
 * @param actual Actual signed character value.
 */
void tst_assert_schar(const char *message, const signed char expected, const signed char actual);

/**
 * @brief Asserts that two unsigned characters are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected unsigned character value.
 * @param actual Actual unsigned character value.
 */
void tst_assert_uchar(const char *message, const unsigned char expected, const unsigned char actual);

/**
 * @brief Asserts that two short integers are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected short integer value.
 * @param actual Actual short integer value.
 */
void tst_assert_short(const char *message, const short expected, const short actual);

/**
 * @brief Asserts that two integers are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected integer value.
 * @param actual Actual integer value.
 */
void tst_assert_int(const char *message, const int expected, const int actual);

/**
 * @brief Asserts that two long integers are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected long integer value.
 * @param actual Actual long integer value.
 */
void tst_assert_long(const char *message, const long expected, const long actual);

/**
 * @brief Asserts that two long long integers are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected long long integer value.
 * @param actual Actual long long integer value.
 */
void tst_assert_long_long(const char *message, const long long expected, const long long actual);

/**
 * @brief Asserts that two unsigned short integers are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected unsigned short integer value.
 * @param actual Actual unsigned short integer value.
 */
void tst_assert_ushort(const char *message, const unsigned short expected, const unsigned short actual);

/**
 * @brief Asserts that two unsigned integers are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected unsigned integer value.
 * @param actual Actual unsigned integer value.
 */
void tst_assert_uint(const char *message, const unsigned int expected, const unsigned int actual);

/**
 * @brief Asserts that two unsigned long integers are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected unsigned long integer value.
 * @param actual Actual unsigned long integer value.
 */
void tst_assert_ulong(const char *message, const unsigned long expected, const unsigned long actual);

/**
 * @brief Asserts that two unsigned long long integers are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected unsigned long long integer value.
 * @param actual Actual unsigned long long integer value.
 */
void tst_assert_ulong_long(const char *message, const unsigned long long expected, const unsigned long long actual);

/**
 * @brief Asserts that two floating point numbers are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected float value.
 * @param actual Actual float value.
 */
void tst_assert_float(const char *message, const float expected, const float actual);

/**
 * @brief Asserts that two double precision floating point numbers are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected double value.
 * @param actual Actual double value.
 */
void tst_assert_double(const char *message, const double expected, const double actual);

/**
 * @brief Asserts that two long double precision floating point numbers are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected long double value.
 * @param actual Actual long double value.
 */
void tst_assert_long_double(const char *message, const long double expected, const long double actual);

/**
 * @brief Asserts that two strings are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected string.
 * @param actual Actual string.
 */
void tst_assert_str(const char *message, const char *expected, const char *actual);

/**
 * @brief Asserts that two int8_t values are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected int8_t value.
 * @param actual Actual int8_t value.
 */
void tst_assert_int8(const char *message, const int8_t expected, const int8_t actual);

/**
 * @brief Asserts that two int16_t values are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected int16_t value.
 * @param actual Actual int16_t value.
 */
void tst_assert_int16(const char *message, const int16_t expected, const int16_t actual);

/**
 * @brief Asserts that two int32_t values are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected int32_t value.
 * @param actual Actual int32_t value.
 */
void tst_assert_int32(const char *message, const int32_t expected, const int32_t actual);

/**
 * @brief Asserts that two int64_t values are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected int64_t value.
 * @param actual Actual int64_t value.
 */
void tst_assert_int64(const char *message, const int64_t expected, const int64_t actual);

/**
 * @brief Asserts that two uint8_t values are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected uint8_t value.
 * @param actual Actual uint8_t value.
 */
void tst_assert_uint8(const char *message, const uint8_t expected, const uint8_t actual);

/**
 * @brief Asserts that two uint16_t values are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected uint16_t value.
 * @param actual Actual uint16_t value.
 */
void tst_assert_uint16(const char *message, const uint16_t expected, const uint16_t actual);

/**
 * @brief Asserts that two uint32_t values are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected uint32_t value.
 * @param actual Actual uint32_t value.
 */
void tst_assert_uint32(const char *message, const uint32_t expected, const uint32_t actual);

/**
 * @brief Asserts that two uint64_t values are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected uint64_t value.
 * @param actual Actual uint64_t value.
 */
void tst_assert_uint64(const char *message, const uint64_t expected, const uint64_t actual);

/**
 * @brief Asserts that two size_t values are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected size_t value.
 * @param actual Actual size_t value.
 */
void tst_assert_size(const char *message, const size_t expected, const size_t actual);

/**
 * @brief Asserts that two intptr_t values are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected intptr_t value.
 * @param actual Actual intptr_t value.
 */
void tst_assert_intptr(const char *message, const intptr_t expected, const intptr_t actual);

/**
 * @brief Asserts that two uintptr_t values are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected uintptr_t value.
 * @param actual Actual uintptr_t value.
 */
void tst_assert_uintptr(const char *message, const uintptr_t expected, const uintptr_t actual);

/**
 * @brief Asserts that two ptrdiff_t values are equal.
 *
 * @param message Error message to display if assertion fails.
 * @param expected Expected ptrdiff_t value.
 * @param actual Actual ptrdiff_t value.
 */
void tst_assert_ptrdiff(const char *message, const ptrdiff_t expected, const ptrdiff_t actual);

#endif /* NEOTEST_NEOTEST_H */
