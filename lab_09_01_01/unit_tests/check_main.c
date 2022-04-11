#include "check_dyn_array.h"
#include "check_film_struct.h"
#include <check.h>


int main(void)
{
    int no_failed = 0;
    // Suite *s;
    Suite *p;
    SRunner *runner;

    // s = dyn_array_suite();
    p = film_struct_suite();

    runner = srunner_create(p);
    // srunner_add_suite(runner, s);

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
