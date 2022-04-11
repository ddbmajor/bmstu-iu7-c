#include "check_list.h"
#include "check_listsort.h"
#include "check_node.h"
#include "check_site.h"
#include <check.h>


int main(void)
{
    int no_failed = 0;
    Suite *s;
    Suite *p;
    Suite *q;
    Suite *t;
    SRunner *runner;

    s = list_suite();
    p = listsort_suite();
    q = node_suite();
    t = site_suite();

    runner = srunner_create(p);
    srunner_add_suite(runner, s);
    srunner_add_suite(runner, q);
    srunner_add_suite(runner, t);

    // Вот таким образом запускаются все тесты. С помощью второго параметра (в данном случаев
    // CK_VERBOSE) можно детализировать вывод.
    srunner_run_all(runner, CK_VERBOSE);
    // После того, как все тесты будут выполнены, можно получить по ним дополнительную информацию,
    // например, вот так.
    no_failed = srunner_ntests_failed(runner);
    // Перед завершением main "runner" нужно обязательно освободить.
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
