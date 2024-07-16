#include <math.h>
#include <neotest/neotest.h>
#include <setjmp.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// Exit from test function
static jmp_buf assert_error;

const float FLOAT_EPSILON = 1e-5f;
const double DOUBLE_EPSILON = 1e-8;

int tst_run_tests(const tst_TestCase test_cases[], const int num_tests) {
    int tests_run = 0;
    int tests_passed = 0;
    int tests_failed = 0;

    printf("=======================================\n");

    for (int i = 0; i < num_tests; ++i) {
        printf(">> Running test: %s\n", test_cases[i].name);

        if (setjmp(assert_error) == 0) {
            test_cases[i].test_function();
            tests_run++;
            tests_passed++;
            printf("<< Test %s passed.\n", test_cases[i].name);
        } else {
            tests_failed++;
            printf("<< Test %s failed.\n", test_cases[i].name);
        }

        printf("---------------------------------------\n");
    }

    printf("Tests run: %d\n", tests_run);
    printf("Tests passed: %d\n", tests_passed);
    printf("Tests failed: %d\n", tests_failed);
    printf("=======================================\n");

    return tests_failed;
}

void tst_fail(const char *message) {
    printf("\tERROR(%s)\n", message);
    longjmp(assert_error, 1);
}

void tst_succeed(const char *message) {
    printf("\tSUCCESS(%s)\n", message);
}

void tst_assert_true(const char *message, const bool comparison_result) {
    if (!comparison_result) {
        printf("\tERROR(%s): expected <true> got <false>\n", message);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_false(const char *message, const bool comparison_result) {
    if (comparison_result) {
        printf("\tERROR(%s): expected <false> got <true>\n", message);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_char(const char *message, const char expected, const char actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%d> and got <%d> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_schar(const char *message, const signed char expected, const signed char actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%d> and got <%d> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_uchar(const char *message, const unsigned char expected, const unsigned char actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%u> and got <%u> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_short(const char *message, const short expected, const short actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%hd> and got <%hd> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_int(const char *message, const int expected, const int actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%d> and got <%d> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_long(const char *message, const long expected, const long actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%ld> and got <%ld> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_long_long(const char *message, const long long expected, const long long actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%lld> and got <%lld> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_ushort(const char *message, const unsigned short expected, const unsigned short actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%hu> and got <%hu> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_uint(const char *message, const unsigned int expected, const unsigned int actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%u> and got <%u> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_ulong(const char *message, const unsigned long expected, const unsigned long actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%lu> and got <%lu> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_ulong_long(const char *message, const unsigned long long expected, const unsigned long long actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%llu> and got <%llu> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_float(const char *message, const float expected, const float actual) {
    if (fabsf(expected - actual) > FLOAT_EPSILON) {
        printf("\tERROR(%s): expected <%f> and got <%f> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_double(const char *message, const double expected, const double actual) {
    if (fabs(expected - actual) > DOUBLE_EPSILON) {
        printf("\tERROR(%s): expected <%lf> and got <%lf> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_long_double(const char *message, const long double expected, const long double actual) {
    if (fabsl(expected - actual) > DOUBLE_EPSILON) {
        printf("\tERROR(%s): expected <%Lf> and got <%Lf> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_str(const char *message, const char *expected, const char *actual) {
    if (strcmp(expected, actual) != 0) {
        printf("\tERROR(%s): expected %s and got %s \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_int8(const char *message, const int8_t expected, const int8_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%d> and got <%d>\n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_int16(const char *message, const int16_t expected, const int16_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%d> and got <%d>\n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_int32(const char *message, const int32_t expected, const int32_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%d> and got <%d>\n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_int64(const char *message, const int64_t expected, const int64_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%lld> and got <%lld>\n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_uint8(const char *message, const uint8_t expected, const uint8_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%u> and got <%u>\n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_uint16(const char *message, const uint16_t expected, const uint16_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%u> and got <%u>\n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_uint32(const char *message, const uint32_t expected, const uint32_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%u> and got <%u>\n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_uint64(const char *message, const uint64_t expected, const uint64_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%llu> and got <%llu>\n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_size(const char *message, const size_t expected, const size_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%zu> and got <%zu>\n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_intptr(const char *message, const intptr_t expected, const intptr_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%jd> and got <%jd>\n", message, (intmax_t) expected, (intmax_t) actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_uintptr(const char *message, const uintptr_t expected, const uintptr_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%ju> and got <%ju>\n", message, (uintmax_t) expected, (uintmax_t) actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_ptrdiff(const char *message, const ptrdiff_t expected, const ptrdiff_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%jd> and got <%jd>\n", message, (intmax_t) expected, (intmax_t) actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}
