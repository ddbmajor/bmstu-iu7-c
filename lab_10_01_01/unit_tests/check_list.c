#include "check_list.h"


START_TEST(test_reverse_empty_list)
{
    node_t *list = NULL;
    list = reverse(list);
    ck_assert_ptr_eq(list, NULL);
}
END_TEST


START_TEST(test_reverse_one_el_list)
{
    node_t *list = create_node(NULL);
    node_t *res_list = list;
    list = reverse(list);
    ck_assert_ptr_eq(list, res_list);
    free(list);
}
END_TEST


START_TEST(test_reverse_list)
{
    node_t *list = create_node(NULL);
    node_t *node = create_node(NULL);
    list->next = node;
    list = reverse(list);
    ck_assert_ptr_eq(list, node);
    free(list->next);
    free(list);
}
END_TEST


START_TEST(test_list_count)
{
    node_t *list = create_node(NULL);
    int counter = 0;
    list_count(list, &counter);
    ck_assert_int_eq(counter, 1);
    free(list);
}
END_TEST


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

    tcase_add_test(tc_pos, test_reverse_empty_list);
    tcase_add_test(tc_pos, test_reverse_one_el_list);
    tcase_add_test(tc_pos, test_reverse_list);
    tcase_add_test(tc_pos, test_list_count);
    tcase_add_test(tc_pos, test_list_append_empty_list);
    tcase_add_test(tc_pos, test_list_append);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
