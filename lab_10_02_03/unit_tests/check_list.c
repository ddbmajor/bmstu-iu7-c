#include "check_list.h"


START_TEST(test_list_append_empty_list)
{
    node_t *list = NULL;
    node_t *node = create_node(NULL);
    list = list_append(list, node);
    ck_assert_ptr_eq(list, node);
    free(node);
}
END_TEST


START_TEST(test_list_append)
{
    node_t *list = create_node(NULL);
    node_t *node = create_node(NULL);
    list = list_append(list, node);
    ck_assert_ptr_eq(list->next, node);
    free(list);
    free(node);
}
END_TEST


Suite* list_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("list");
    
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_list_append_empty_list);
    tcase_add_test(tc_pos, test_list_append);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
