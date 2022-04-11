#include "check_my_stdio.h"


START_TEST(test_neg_not_null_buffer_zero_size)
{
    char str[5] = "";
    char my_str[5] = "";
    int size = 0;
    char print[] = "print";
    int rc;
    int my_rc;
    rc = snprintf(str, size, "%s", print);
    my_rc = my_snprintf(my_str, size, "%s", print);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_str_eq(str, my_str);
}
END_TEST


START_TEST(test_neg_null_buffer_zero_size)
{
    char *str = NULL;
    char *my_str = NULL;
    int size = 0;
    char print[] = "print";
    int rc;
    int my_rc;
    rc = snprintf(str, size, "%s", print);
    my_rc = my_snprintf(my_str, size, "%s", print);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_int_eq(!str ? 1 : 0, !my_str ? 1 : 0);
}
END_TEST


START_TEST(test_neg_null_format)
{
    char str[5] = "";
    char my_str[5] = "";
    int size = 5;
    char print[] = "print";
    char *format = NULL;
    int rc;
    int my_rc;
    rc = snprintf(str, size, format, print);
    my_rc = my_snprintf(my_str, size, format, print);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_str_eq(str, my_str);
}
END_TEST


START_TEST(test_pos_str_one_char)
{
    char str[5];
    char my_str[5];
    int size = 5;
    char print[] = "p";
    int rc;
    int my_rc;
    rc = snprintf(str, size, "%s", print);
    my_rc = my_snprintf(my_str, size, "%s", print);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_str_eq(str, my_str);
}
END_TEST


START_TEST(test_pos_str_less_then_max_char)
{
    char str[5];
    char my_str[5];
    int size = 5;
    char print[] = "prin";
    int rc;
    int my_rc;
    rc = snprintf(str, size, "%s", print);
    my_rc = my_snprintf(my_str, size, "%s", print);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_str_eq(str, my_str);
}
END_TEST


START_TEST(test_pos_str_max_char)
{
    char str[5];
    char my_str[5];
    int size = 5;
    char print[] = "print";
    int rc;
    int my_rc;
    rc = snprintf(str, size, "%s", print);
    my_rc = my_snprintf(my_str, size, "%s", print);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_str_eq(str, my_str);
}
END_TEST


START_TEST(test_pos_str_more_then_max_char)
{
    char str[5];
    char my_str[5];
    int size = 5;
    char print[] = "print something";
    int rc;
    int my_rc;
    rc = snprintf(str, size, "%s", print);
    my_rc = my_snprintf(my_str, size, "%s", print);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_str_eq(str, my_str);
}
END_TEST


START_TEST(test_pos_llx_zero)
{
    char str[5];
    char my_str[5];
    int size = 5;
    long long int print = 0;
    int rc;
    int my_rc;
    rc = snprintf(str, size, "%llx", (long long unsigned int)print);
    my_rc = my_snprintf(my_str, size, "%llx", (long long unsigned int)print);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_str_eq(str, my_str);
}
END_TEST


START_TEST(test_pos_llx)
{
    char str[5];
    char my_str[5];
    int size = 5;
    long long int print = 125;
    int rc;
    int my_rc;
    rc = snprintf(str, size, "%llx", (long long unsigned int)print);
    my_rc = my_snprintf(my_str, size, "%llx", (long long unsigned int)print);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_str_eq(str, my_str);
}
END_TEST


START_TEST(test_pos_llx_neg)
{
    char str[16];
    char my_str[16];
    int size = 16;
    long long int print = -125;
    int rc;
    int my_rc;
    rc = snprintf(str, size, "%llx", (long long unsigned int)print);
    my_rc = my_snprintf(my_str, size, "%llx", (long long unsigned int)print);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_str_eq(str, my_str);
}
END_TEST


START_TEST(test_pos_llx_max)
{
    char str[17];
    char my_str[17];
    int size = 17;
    unsigned long long int print = __UINT64_MAX__;
    int rc;
    int my_rc;
    rc = snprintf(str, size, "%llx", (long long unsigned int)print);
    my_rc = my_snprintf(my_str, size, "%llx", (long long unsigned int)print);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_str_eq(str, my_str);
}
END_TEST


Suite* my_stdio_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("my_snprintf");
    
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_neg_not_null_buffer_zero_size);
    tcase_add_test(tc_neg, test_neg_null_buffer_zero_size);
    tcase_add_test(tc_neg, test_neg_null_format);
    tcase_add_test(tc_pos, test_pos_str_one_char);
    tcase_add_test(tc_pos, test_pos_str_less_then_max_char);
    tcase_add_test(tc_pos, test_pos_str_max_char);
    tcase_add_test(tc_pos, test_pos_str_more_then_max_char);
    tcase_add_test(tc_pos, test_pos_llx);
    tcase_add_test(tc_pos, test_pos_llx_neg);
    tcase_add_test(tc_pos, test_pos_llx_zero);
    tcase_add_test(tc_pos, test_pos_llx_max);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}
