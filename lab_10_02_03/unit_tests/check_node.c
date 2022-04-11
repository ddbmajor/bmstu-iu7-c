#include "check_node.h"


START_TEST(test_create_node)
{
    int rc = 0;
    node_t *node = create_node(NULL);
    if (node)
        rc = 1;
    ck_assert_int_eq(rc, 1);
    ck_assert_ptr_eq(node->data, NULL);
    free(node);
}
END_TEST


Suite* node_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("node");
    
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_create_node);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
