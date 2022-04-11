#include "check_factor.h"

START_TEST(test_create_factor)
{
    int rc = 0;
    factor_t *factor = create_factor(1);
    if (factor)
        rc = 1;

    ck_assert_int_eq(rc, 1);
    ck_assert_int_eq(factor->power, 1);
    free(factor);
}
END_TEST



Suite* factor_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("factor");
    
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_create_factor);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
