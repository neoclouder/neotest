#include <neotest/neotest.h>

void test_msg(void) {
    tst_fail("Testing fails");
}

void test_true_assertion(void) {
    tst_assert_true("Testing true assertion", false);
}

void test_false_assertion(void) {
    tst_assert_false("Testing true assertion", true);
}

void test_char_assertion(void) {
    tst_assert_char("Testing char assertion", 'A', 'b');
}

void test_schar_assertion(void) {
    tst_assert_schar("Testing signed char assertion", -127, -126);
}

void test_uchar_assertion(void) {
    tst_assert_uchar("Testing unsigned char assertion", 255, 254);
}

void test_short_assertion(void) {
    tst_assert_short("Testing short assertion", 32767, 32766);
}

void test_int_assertion(void) {
    tst_assert_int("Testing int assertion", 2147483647, 2147483646);
}

void test_long_assertion(void) {
    tst_assert_long("Testing long assertion", 9223372036854775807L, 9223372036854775806L);
}

void test_long_long_assertion(void) {
    tst_assert_long_long("Testing long long assertion", 9223372036854775807LL, 9223372036854775806LL);
}

void test_ushort_assertion(void) {
    tst_assert_ushort("Testing unsigned short assertion", 65535, 65534);
}

void test_uint_assertion(void) {
    tst_assert_uint("Testing unsigned int assertion", 4294967295U, 4294967294U);
}

void test_ulong_assertion(void) {
    tst_assert_ulong("Testing unsigned long assertion", 18446744073709551615UL, 18446744073709551614UL);
}

void test_ulong_long_assertion(void) {
    tst_assert_ulong_long("Testing unsigned long long assertion", 18446744073709551615ULL, 18446744073709551614ULL);
}

void test_int8_assertion(void) {
    tst_assert_int8("Testing int8_t assertion", 1, 2);
}

void test_int16_assertion(void) {
    tst_assert_int16("Testing int16_t assertion", 1, 2);
}

void test_int32_assertion(void) {
    tst_assert_int32("Testing int32_t assertion", 1, 2);
}

void test_int64_assertion(void) {
    tst_assert_int64("Testing int64_t assertion", 1, 2);
}

void test_uint8_assertion(void) {
    tst_assert_uint8("Testing uint8_t assertion", 1, 2);
}

void test_uint16_assertion(void) {
    tst_assert_uint16("Testing uint16_t assertion", 1, 2);
}

void test_uint32_assertion(void) {
    tst_assert_uint32("Testing uint32_t assertion", 1, 2);
}

void test_uint64_assertion(void) {
    tst_assert_uint64("Testing uint64_t assertion", 1, 2);
}

void test_size_assertion(void) {
    tst_assert_size("Testing size_t assertion", 1, 2);
}

void test_intptr_assertion(void) {
    tst_assert_intptr("Testing intptr_t assertion", 1, 2);
}

void test_uintptr_assertion(void) {
    tst_assert_uintptr("Testing uintptr_t assertion", 1, 2);
}

void test_ptrdiff_assertion(void) {
    tst_assert_ptrdiff("Testing ptrdiff_t assertion", 1, 2);
}

void test_float_assertion(void) {
    tst_assert_float("Testing float assertion", 1.234f, 1.233f);
}

void test_double_assertion(void) {
    tst_assert_double("Testing double assertion", 3.456, 3.454);
}

void test_long_double_assertion(void) {
    tst_assert_long_double("Testing double assertion", 3.456L, 3.457L);
}

int main(void) {

    const tst_TestCase test_cases[] = {
        {"Fail message", test_msg},
        {"True Assertion", test_true_assertion},
        {"False Assertion", test_false_assertion},
        {"Char Assertion", test_char_assertion},
        {"Signed Char Assertion", test_schar_assertion},
        {"Unsigned Char Assertion", test_uchar_assertion},
        {"Short Assertion", test_short_assertion},
        {"Integer Assertion", test_int_assertion},
        {"Long Assertion", test_long_assertion},
        {"Long Long Assertion", test_long_long_assertion},
        {"Unsigned Short Assertion", test_ushort_assertion},
        {"Unsigned Integer Assertion", test_uint_assertion},
        {"Unsigned Long Assertion", test_ulong_assertion},
        {"Unsigned Long Long Assertion", test_ulong_long_assertion},
        {"int8_t Assertion", test_int8_assertion},
        {"int16_t Assertion", test_int16_assertion},
        {"int32_t Assertion", test_int32_assertion},
        {"int64_t Assertion", test_int64_assertion},
        {"Unsigned int8_t Assertion", test_uint8_assertion},
        {"Unsigned int16_t Assertion", test_uint16_assertion},
        {"Unsigned int32_t Assertion", test_uint32_assertion},
        {"Unsigned int64_t Assertion", test_uint64_assertion},
        {"Unsigned int64_t Assertion", test_uint64_assertion},
        {"size_t Assertion", test_size_assertion},
        {"intptr_t Assertion", test_intptr_assertion},
        {"uintptr_t Assertion", test_uintptr_assertion},
        {"intptr_t Assertion", test_intptr_assertion},
        {"ptrdiff Assertion", test_ptrdiff_assertion},
        {"Float Assertion", test_float_assertion},
        {"Double Assertion", test_double_assertion},
        {"Long Double Assertion", test_long_double_assertion},
    };
    return tst_run_tests(test_cases, sizeof(test_cases) / sizeof(tst_TestCase));
}
