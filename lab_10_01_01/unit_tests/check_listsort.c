#include "check_listsort.h"

START_TEST(test_front_back_split_empty_list)
{
    node_t *list = NULL;
    node_t *back = NULL;
    front_back_split(list, &back);
    ck_assert_ptr_eq(list, NULL);
    ck_assert_ptr_eq(back, NULL);
}
END_TEST


START_TEST(test_front_back_split_one_el_list)
{
    node_t *node = create_node(NULL);
    node_t *list = node;
    node_t *back = NULL;
    front_back_split(list, &back);
    ck_assert_ptr_eq(list, node);
    ck_assert_ptr_eq(back, NULL);
    free(node);
}
END_TEST


START_TEST(test_front_back_split_two_el_list)
{
    node_t *node1 = create_node(NULL);
    node_t *node2 = create_node(NULL);
    node_t *list = node1;
    list->next = node2;
    node_t *back = NULL;
    front_back_split(list, &back);
    ck_assert_ptr_eq(list, node1);
    ck_assert_ptr_eq(back, node2);
    free(node1);
    free(node2);
}
END_TEST


START_TEST(test_front_back_split_three_el_list)
{
    node_t *node1 = create_node(NULL);
    node_t *node2 = create_node(NULL);
    node_t *node3 = create_node(NULL);
    node_t *list = node1;
    list->next = node2;
    list->next->next = node3;
    node_t *back = NULL;

    front_back_split(list, &back);
    ck_assert_ptr_eq(list, node1);
    ck_assert_ptr_eq(list->next, node2);
    ck_assert_ptr_eq(back, node3);
    free(node1);
    free(node2);
    free(node3);
}
END_TEST


START_TEST(test_sorted_merge_empty_lists)
{
    node_t *list1 = NULL;
    node_t *list2 = NULL;
    node_t *res_list = NULL;

    res_list = sorted_merge(&list1, &list2, site_visitors_compare);

    ck_assert_ptr_eq(res_list, NULL);
}
END_TEST


START_TEST(test_sorted_merge_one_el_list)
{
    node_t *node = create_node(NULL);
    node_t *list1 = node;
    node_t *list2 = NULL;
    node_t *res_list = NULL;

    res_list = sorted_merge(&list1, &list2, site_visitors_compare);

    ck_assert_ptr_eq(res_list, node);
    ck_assert_ptr_eq(list1, NULL);
    ck_assert_ptr_eq(list2, NULL);
    free(node);
}
END_TEST


Suite* listsort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("listsort");
    
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_front_back_split_empty_list);
    tcase_add_test(tc_pos, test_front_back_split_one_el_list);
    tcase_add_test(tc_pos, test_front_back_split_two_el_list);
    tcase_add_test(tc_pos, test_front_back_split_three_el_list);
    tcase_add_test(tc_pos, test_sorted_merge_empty_lists);
    tcase_add_test(tc_pos, test_sorted_merge_one_el_list);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
