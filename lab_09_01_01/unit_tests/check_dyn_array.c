#include "check_dyn_array.h"


START_TEST(test_append)
{
    int rc;
    struct dyn_array arr;
    init_dyn_array(&arr);

    struct film film = {.title = "abc", .name = "xyz", .year = 123};

    struct dyn_array arr_res;
    init_dyn_array(&arr_res);
    arr_res.data = malloc(sizeof(struct film));
    arr_res.data[0] = film;
    arr_res.allocated = 1;
    arr_res.len = 1;

    rc = append(&arr, film);
    ck_assert_int_eq(rc, 0);

    ck_assert_int_eq(arr.len, arr_res.len);
    ck_assert_mem_eq(arr.data, arr_res.data, arr.len * sizeof(struct film));
    ck_assert_int_eq(arr.allocated, arr_res.allocated);
    
    free(arr.data);
    free(arr_res.data);
}
END_TEST


Suite* dyn_array_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("dyn_array");
    
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_append);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
