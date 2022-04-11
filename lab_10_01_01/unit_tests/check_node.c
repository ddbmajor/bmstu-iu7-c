#include "check_node.h"


static int int_compare(const void *a, const void *b)
{
    const int *l = a;
    const int *r = b;
    return *l - *r;
}


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


START_TEST(test_find_empty_list)
{
    node_t *list = NULL;
    node_t *res = find(list, NULL, int_compare);
    ck_assert_ptr_eq(res, NULL);
}
END_TEST


START_TEST(test_find_one_el_list)
{
    int num = 1;
    node_t *list = create_node((void *)&num);
    node_t *res = find(list, (void *)&num, int_compare);
    ck_assert_ptr_eq(res, list);
    free(list);
}


START_TEST(test_pop_back_empty_list)
{
    node_t *list = NULL;
    void *res = pop_back(&list);
    ck_assert_ptr_eq(res, NULL);
    ck_assert_ptr_eq(list, NULL);
}
END_TEST


START_TEST(test_pop_back_one_el_list)
{
    node_t *list = create_node(NULL);
    void *res = pop_back(&list);
    ck_assert_ptr_eq(res, NULL);
    ck_assert_ptr_eq(list, NULL);
}

START_TEST(test_pop_back_two_el_list)
{
    int n1 = 1, n2 = 2;
    node_t *node1 = create_node((void *)&n1);
    node_t *node2 = create_node((void *)&n2);
    node_t *list = node1;
    list->next = node2;

    void *res = pop_back(&list);
    ck_assert_ptr_eq(res, &n2);
    ck_assert_ptr_eq(list, node1);
    free(node1);
}


Suite* node_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("node");
    
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_create_node);
    tcase_add_test(tc_pos, test_find_empty_list);
    tcase_add_test(tc_pos, test_find_one_el_list);
    tcase_add_test(tc_pos, test_pop_back_empty_list);
    tcase_add_test(tc_pos, test_pop_back_one_el_list);
    tcase_add_test(tc_pos, test_pop_back_two_el_list);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
