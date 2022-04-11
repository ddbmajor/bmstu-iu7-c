#include "check_film_struct.h"

START_TEST(test_isstrspace_pos)
{
    int rc;
    char *str = "  ";
    rc = isstrspace(str);
    ck_assert_int_eq(rc, 1);
}
END_TEST


START_TEST(test_isstrspace_neg)
{
    int rc;
    char *str = " ghj ";
    rc = isstrspace(str);
    ck_assert_int_eq(rc, 0);
}
END_TEST


START_TEST(test_strndel)
{
    char str[] = "wefewfd\n";
    char strres[] = "wefewfd";
    strndel(str);
    ck_assert_str_eq(str, strres);
}
END_TEST


Suite* film_struct_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("film_struct");
    
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_isstrspace_pos);
    tcase_add_test(tc_pos, test_isstrspace_neg);
    tcase_add_test(tc_pos, test_strndel);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
