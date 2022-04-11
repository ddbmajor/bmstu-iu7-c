#include "check_libfuncs.h"


START_TEST(test_neg_fib_fill_null_arr)
{
    int rc = fibFillArray(NULL, 0);
    ck_assert_int_eq(rc, NULL_ARRAY_ERROR);
}
END_TEST

START_TEST(test_neg_fib_fill_zero_size)
{
    int arr[4] = { 0 };
    int rc = fibFillArray(arr, 0);
    ck_assert_int_eq(rc, SIZE_ERROR);
}
END_TEST

START_TEST(test_neg_fib_fill_neg_size)
{
    int arr[4] = { 0 };
    int rc = fibFillArray(arr, -1);
    ck_assert_int_eq(rc, SIZE_ERROR);
}
END_TEST

START_TEST(test_pos_fib_fill_one_el)
{
    int arr[1] = { -1 };
    int rc = fibFillArray(arr, 1);
    ck_assert_int_eq(rc, 0);
    ck_assert_int_eq(arr[0], 0);
}
END_TEST

START_TEST(test_pos_fib_fill_two_el)
{
    int arr[2] = { 0 };
    int res[2] = { 0, 1};
    int rc = fibFillArray(arr, 2);
    ck_assert_int_eq(rc, 0);
    ck_assert_mem_eq(arr, res, 2 * sizeof(int));
}
END_TEST

START_TEST(test_pos_fib_fill_five_el)
{
    int arr[5] = { 0 };
    int res[5] = {0, 1, 1, 2, 3};
    int rc = fibFillArray(arr, 5);
    ck_assert_int_eq(rc, 0);
    ck_assert_mem_eq(arr, res, 5 * sizeof(int));
}
END_TEST

START_TEST(test_neg_uniq_arr_null_src_arr)
{
    int rc = uniqueArray(NULL, 1, NULL, 0);
    ck_assert_int_eq(rc, NULL_ARRAY_ERROR);
}

START_TEST(test_neg_uniq_arr_zero_size_src_arr)
{
    int arr[1] = { 0 };
    int rc = uniqueArray(arr, 0, NULL, 0);
    ck_assert_int_eq(rc, SIZE_ERROR);
}

START_TEST(test_neg_uniq_arr_neg_size_src_arr)
{
    int arr[1] = { 0 };
    int rc = uniqueArray(arr, -2, NULL, 0);
    ck_assert_int_eq(rc, SIZE_ERROR);
}

START_TEST(test_neg_uniq_arr_not_enough_size_dst_arr)
{
    int arr[2] = { 0, 1 };
    int dst[1] = { 0 };
    int rc = uniqueArray(arr, 2, dst, 1);
    ck_assert_int_eq(rc, 2);
}

START_TEST(test_neg_uniq_arr_null_dst_arr)
{
    int arr[2] = { 0, 1 };
    // int dst[1] = { 0 }
    int rc = uniqueArray(arr, 2, NULL, 3);
    ck_assert_int_eq(rc, NULL_ARRAY_ERROR);
}

START_TEST(test_pos_uniq_arr_no_doubles)
{
    int arr[2] = { 0, 1 };
    int dst[2] = { 0 };
    int rc = uniqueArray(arr, 2, dst, 2);
    ck_assert_int_eq(rc, 0);
    ck_assert_mem_eq(arr, dst, 2 * sizeof(int));
}

START_TEST(test_pos_uniq_arr_doubles)
{
    int arr[2] = { 1, 1 };
    int dst[1] = { 0 };
    int rc = uniqueArray(arr, 2, dst, 2);
    ck_assert_int_eq(rc, 0);
    ck_assert_int_eq(arr[0], dst[0]);
}

Suite* libfuncs_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("libfunc");
    
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_neg_fib_fill_null_arr);
    tcase_add_test(tc_neg, test_neg_fib_fill_zero_size);
    tcase_add_test(tc_neg, test_neg_fib_fill_neg_size);

    tcase_add_test(tc_pos, test_pos_fib_fill_one_el);
    tcase_add_test(tc_pos, test_pos_fib_fill_two_el);
    tcase_add_test(tc_pos, test_pos_fib_fill_five_el);

    tcase_add_test(tc_neg, test_neg_uniq_arr_null_src_arr);
    tcase_add_test(tc_neg, test_neg_uniq_arr_null_dst_arr);
    tcase_add_test(tc_neg, test_neg_uniq_arr_neg_size_src_arr);
    tcase_add_test(tc_neg, test_neg_uniq_arr_zero_size_src_arr);
    tcase_add_test(tc_neg, test_neg_uniq_arr_not_enough_size_dst_arr);

    tcase_add_test(tc_pos, test_pos_uniq_arr_no_doubles);
    tcase_add_test(tc_pos, test_pos_uniq_arr_doubles);
    

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    

    return s;
}