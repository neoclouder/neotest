#include <limits.h>
#include <neotest/neotest.h>
#include <stdint.h>

void test_msg(void) {
    tst_succeed("Testing success");
}

void test_bool_assertions(void) {
    tst_assert_true("Testing true assertion", true);
    tst_assert_false("Testing true assertion", false);
}

void test_char_assertions(void) {
    tst_assert_char("Testing char assertion", 'A', 'A');
    tst_assert_schar("Testing signed char assertion", -127, -127);
    tst_assert_uchar("Testing unsigned char assertion", 255, 255);
}

void test_str_assertions(void) {
    tst_assert_str("Testing string assertion", "Hello world!", "Hello world!");
}

void test_int_assertions(void) {
    tst_assert_short("Testing short assertion", SHRT_MAX, SHRT_MAX);
    tst_assert_int("Testing int assertion", INT_MAX, INT_MAX);
    tst_assert_long("Testing long assertion", LONG_MAX, LONG_MAX);
    tst_assert_long_long("Testing long long assertion", LONG_LONG_MAX, LONG_LONG_MAX);
    tst_assert_ushort("Testing unsigned short assertion", USHRT_MAX, USHRT_MAX);
    tst_assert_uint("Testing unsigned int assertion", UINT_MAX, UINT_MAX);
    tst_assert_ulong("Testing unsigned long assertion", ULONG_MAX, ULONG_MAX);
    tst_assert_ulong_long("Testing unsigned long long assertion", ULONG_LONG_MAX, ULONG_LONG_MAX);
    tst_assert_int8("Testing int8_t assertion", INT8_MIN, INT8_MIN);
    tst_assert_int16("Testing int16_t assertion", INT16_MIN, INT16_MIN);
    tst_assert_int32("Testing int32_t assertion", INT32_MIN, INT32_MIN);
    tst_assert_int64("Testing int64_t assertion", INT64_MIN, INT64_MIN);
    tst_assert_uint8("Testing uint8_t assertion", UINT8_MAX, UINT8_MAX);
    tst_assert_uint16("Testing uint16_t assertion", UINT16_MAX, UINT16_MAX);
    tst_assert_uint32("Testing uint32_t assertion", UINT32_MAX, UINT32_MAX);
    tst_assert_uint64("Testing uint64_t assertion", UINT64_MAX, UINT64_MAX);
    tst_assert_size("Testing size_t assertion", SIZE_MAX, SIZE_MAX);
    tst_assert_intptr("Testing intptr_t assertion", INTPTR_MIN, INTPTR_MIN);
    tst_assert_uintptr("Testing uintptr_t assertion", UINTPTR_MAX, UINTPTR_MAX);
    tst_assert_ptrdiff("Testing ptrdiff_t assertion", PTRDIFF_MIN, PTRDIFF_MIN);
}

void test_float_assertions(void) {
    tst_assert_float("Testing float assertion", 1.234f, 1.234f);
    tst_assert_double("Testing double assertion", 3.456, 3.456);
    tst_assert_long_double("Testing double assertion", 3.456L, 3.456L);
}

int main(void) {
    const tst_TestCase test_cases[] = {
        {"Success message", test_msg},
        {"Bool Assertions", test_bool_assertions},
        {"Char Assertions", test_char_assertions},
        {"String Assertions", test_str_assertions},
        {"Integer Assertions", test_int_assertions},
        {"Float Assertions", test_float_assertions},
    };

    return tst_run_tests(test_cases, sizeof(test_cases) / sizeof(tst_TestCase));
}
