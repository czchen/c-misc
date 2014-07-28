#include <check.h>

#include <simple-hash.h>

START_TEST(test_hash)
{
    // FIXME: Implement this
}
END_TEST

int main()
{
    Suite *suite = suite_create("test-hash");

    TCase *tcase = tcase_create("run hash");
    tcase_add_test(tcase, test_hash);

    suite_add_tcase(suite, tcase);

    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);

    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return !!number_failed;
}
