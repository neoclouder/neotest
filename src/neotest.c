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

int tst_run_tests(const tst_TestCase test_cases[], int num_tests) {
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

void tst_assert_true(const char *message, bool comparison_result) {
    if (!comparison_result) {
        printf("\tERROR(%s): expected <true> got <false>\n", message);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_false(const char *message, bool comparison_result) {
    if (comparison_result) {
        printf("\tERROR(%s): expected <false> got <true>\n", message);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_char(const char *message, char expected, char actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%d> and got <%d> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_schar(const char *message, signed char expected, signed char actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%d> and got <%d> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_uchar(const char *message, unsigned char expected, unsigned char actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%u> and got <%u> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_short(const char *message, short expected, short actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%hd> and got <%hd> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_int(const char *message, int expected, int actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%d> and got <%d> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_long(const char *message, long expected, long actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%ld> and got <%ld> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_long_long(const char *message, long long expected, long long actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%lld> and got <%lld> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_ushort(const char *message, unsigned short expected, unsigned short actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%hu> and got <%hu> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_uint(const char *message, unsigned int expected, unsigned int actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%u> and got <%u> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_ulong(const char *message, unsigned long expected, unsigned long actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%lu> and got <%lu> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_ulong_long(const char *message, unsigned long long expected, unsigned long long actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%llu> and got <%llu> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_float(const char *message, float expected, float actual) {
    if (fabsf(expected - actual) > FLOAT_EPSILON) {
        printf("\tERROR(%s): expected <%f> and got <%f> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_double(const char *message, double expected, double actual) {
    if (fabs(expected - actual) > DOUBLE_EPSILON) {
        printf("\tERROR(%s): expected <%lf> and got <%lf> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_long_double(const char *message, long double expected, long double actual) {
    if (fabsl(expected - actual) > DOUBLE_EPSILON) {
        printf("\tERROR(%s): expected <%Lf> and got <%Lf> \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_str(const char *message, char *expected, char *actual) {
    if (strcmp(expected, actual) != 0) {
        printf("\tERROR(%s): expected %s and got %s \n", message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", message);
    }
}

void tst_assert_int8(const char *error_message, int8_t expected, int8_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%d> and got <%d>\n", error_message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", error_message);
    }
}

void tst_assert_int16(const char *error_message, int16_t expected, int16_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%d> and got <%d>\n", error_message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", error_message);
    }
}

void tst_assert_int32(const char *error_message, int32_t expected, int32_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%d> and got <%d>\n", error_message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", error_message);
    }
}

void tst_assert_int64(const char *error_message, int64_t expected, int64_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%lld> and got <%lld>\n", error_message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", error_message);
    }
}

void tst_assert_uint8(const char *error_message, uint8_t expected, uint8_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%u> and got <%u>\n", error_message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", error_message);
    }
}

void tst_assert_uint16(const char *error_message, uint16_t expected, uint16_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%u> and got <%u>\n", error_message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", error_message);
    }
}

void tst_assert_uint32(const char *error_message, uint32_t expected, uint32_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%u> and got <%u>\n", error_message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", error_message);
    }
}

void tst_assert_uint64(const char *error_message, uint64_t expected, uint64_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%llu> and got <%llu>\n", error_message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", error_message);
    }
}

void tst_assert_size(const char *error_message, size_t expected, size_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%zu> and got <%zu>\n", error_message, expected, actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", error_message);
    }
}

void tst_assert_intptr(const char *error_message, intptr_t expected, intptr_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%jd> and got <%jd>\n", error_message, (intmax_t)expected, (intmax_t)actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", error_message);
    }
}

void tst_assert_uintptr(const char *error_message, uintptr_t expected, uintptr_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%ju> and got <%ju>\n", error_message, (uintmax_t)expected, (uintmax_t)actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", error_message);
    }
}

void tst_assert_ptrdiff(const char *error_message, ptrdiff_t expected, ptrdiff_t actual) {
    if (expected != actual) {
        printf("\tERROR(%s): expected <%jd> and got <%jd>\n", error_message, (intmax_t)expected, (intmax_t)actual);
        longjmp(assert_error, 1);
    } else {
        printf("\tSUCCESS(%s)\n", error_message);
    }
}
