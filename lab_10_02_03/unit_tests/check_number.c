#include "check_number.h"

START_TEST(test_create_number_one)
{
    node_t *number = NULL;
    number = create_number(1);
    ck_assert_ptr_eq(number, NULL);
    delete_list(number, delete_factor);
}
END_TEST


START_TEST(test_create_number_two)
{
    node_t *num = create_number(2);

    ck_assert_int_eq(1, ((factor_t *)(num->data))->power);
    delete_list(num, delete_factor);
}


START_TEST(test_multiply_one_on_one)
{
    node_t *num1 = create_number(1);
    node_t *num2 = create_number(1);
    node_t *res = multiply(num1, num2);

    ck_assert_ptr_eq(res, NULL);
    delete_list(num1, delete_factor);
    delete_list(num2, delete_factor);
    delete_list(res, delete_factor);
}
END_TEST


START_TEST(test_multiply_two_on_two)
{
    node_t *num1 = create_number(2);
    node_t *num2 = create_number(2);
    node_t *res = multiply(num1, num2);

    ck_assert_int_eq(((factor_t *)(res->data))->power, 2);
    delete_list(num1, delete_factor);
    delete_list(num2, delete_factor);
    delete_list(res, delete_factor);
}
END_TEST


START_TEST(test_multiply_two_on_three)
{
    node_t *num1 = create_number(2);
    node_t *num2 = create_number(3);
    node_t *res = multiply(num1, num2);

    ck_assert_int_eq(((factor_t *)(res->data))->power, 1);
    ck_assert_int_eq(((factor_t *)(res->next->data))->power, 1);
    delete_list(num1, delete_factor);
    delete_list(num2, delete_factor);
    delete_list(res, delete_factor);
}
END_TEST


START_TEST(test_square_one)
{
    node_t *num = create_number(1);
    node_t *res = square(num);
    ck_assert_ptr_eq(res, NULL);
    delete_list(num, delete_factor);
    delete_list(res, delete_factor);
}
END_TEST


START_TEST(test_square_two)
{
    node_t *num = create_number(2);
    num = square(num);
    ck_assert_int_eq(((factor_t *)(num->data))->power, 2);
    delete_list(num, delete_factor);
}
END_TEST


START_TEST(test_division_one_on_one)
{
    node_t *num1 = create_number(1);
    node_t *num2 = create_number(1);
    node_t *res = NULL;
    int rc = division(&res, num1, num2);
    ck_assert_ptr_eq(res, NULL);
    ck_assert_int_eq(rc, 0);
    delete_list(num1, delete_factor);
    delete_list(num2, delete_factor);
    delete_list(res, delete_factor);
}
END_TEST


START_TEST(test_division_two_on_two)
{
    node_t *num1 = create_number(2);
    node_t *num2 = create_number(2);
    node_t *res = NULL;
    int rc = division(&res, num1, num2);
    ck_assert_ptr_eq(res, NULL);
    ck_assert_int_eq(rc, 0);
    delete_list(num1, delete_factor);
    delete_list(num2, delete_factor);
    delete_list(res, delete_factor);
}
END_TEST


START_TEST(test_division_four_on_two)
{
    node_t *num1 = create_number(4);
    node_t *num2 = create_number(2);
    node_t *res = NULL;
    int rc = division(&res, num1, num2);
    ck_assert_int_eq(((factor_t *)(res->data))->power, 1);
    ck_assert_int_eq(rc, 0);
    delete_list(num1, delete_factor);
    delete_list(num2, delete_factor);
    delete_list(res, delete_factor);
}
END_TEST


START_TEST(test_division_8_on_3)
{
    node_t *num1 = create_number(8);
    node_t *num2 = create_number(3);
    node_t *res = NULL;
    int rc = division(&res, num1, num2);

    ck_assert_int_eq(((factor_t *)(res->data))->power, 1);
    ck_assert_int_eq(rc, 0);

    delete_list(num1, delete_factor);
    delete_list(num2, delete_factor);
    delete_list(res, delete_factor);
}
END_TEST


START_TEST(test_division_neg)
{
    node_t *num1 = create_number(3);
    node_t *num2 = create_number(7);
    node_t *res = NULL;
    int rc = division(&res, num1, num2);

    ck_assert_ptr_eq(res, NULL);
    ck_assert_int_eq(rc, ZERO_ERROR);

    delete_list(num1, delete_factor);
    delete_list(num2, delete_factor);
    delete_list(res, delete_factor);
}
END_TEST


Suite* number_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("number");
    
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_create_number_one);
    tcase_add_test(tc_pos, test_create_number_two);
    tcase_add_test(tc_pos, test_multiply_one_on_one);
    tcase_add_test(tc_pos, test_multiply_two_on_three);
    tcase_add_test(tc_pos, test_multiply_two_on_two);
    tcase_add_test(tc_pos, test_square_one);
    tcase_add_test(tc_pos, test_square_two);
    tcase_add_test(tc_pos, test_division_one_on_one);
    tcase_add_test(tc_pos, test_division_two_on_two);
    tcase_add_test(tc_pos, test_division_four_on_two);
    tcase_add_test(tc_pos, test_division_8_on_3);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_division_neg);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}
