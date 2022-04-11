#include "check_site.h"

START_TEST(test_create_site)
{
    int rc = 0;
    site_t *site = create_site(NULL, NULL, 1);
    if (site)
        rc = 1;

    ck_assert_int_eq(rc, 1);
    free(site);
}
END_TEST


START_TEST(test_site_visitors_compare_less)
{
    site_t site1 = {.theme = NULL, .title = NULL, .visitors = 1};
    site_t site2 = {.theme = NULL, .title = NULL, .visitors = 2};
    int rc = site_visitors_compare((void *)&site1, (void *)&site2);
    ck_assert_int_eq(rc, -1);
}
END_TEST


START_TEST(test_site_visitors_compare_more)
{
    site_t site1 = {.theme = NULL, .title = NULL, .visitors = 2};
    site_t site2 = {.theme = NULL, .title = NULL, .visitors = 1};
    int rc = site_visitors_compare((void *)&site1, (void *)&site2);
    ck_assert_int_eq(rc, 1);
}
END_TEST


START_TEST(test_site_visitors_compare_eq)
{
    site_t site1 = {.theme = NULL, .title = NULL, .visitors = 1};
    site_t site2 = {.theme = NULL, .title = NULL, .visitors = 1};
    int rc = site_visitors_compare((void *)&site1, (void *)&site2);
    ck_assert_int_eq(rc, 0);
}
END_TEST


Suite* site_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("site");
    
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_create_site);
    tcase_add_test(tc_pos, test_site_visitors_compare_less);
    tcase_add_test(tc_pos, test_site_visitors_compare_more);
    tcase_add_test(tc_pos, test_site_visitors_compare_eq);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
