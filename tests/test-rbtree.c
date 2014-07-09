#include <check.h>

#include <rbtree.h>

START_TEST(test_init_destroy)
{

    struct RBTree tree;
    ck_assert_int_eq(init_rbtree(&tree), 0);
    destroy_rbtree(&tree);
}
END_TEST

int main()
{
    Suite *suite = suite_create("test-rbtree");

    TCase *tcase = tcase_create("");
    tcase_add_test(tcase, test_init_destroy);

    suite_add_tcase(suite, tcase);

    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);

    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return !!number_failed;
}
