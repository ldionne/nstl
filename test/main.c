/**
 * Main for the unit tests of nstl.
 */

#include <seatest.h>


extern void test_suite_algorithm(void);
extern void test_suite_container(void);
extern void test_suite_iterator(void);
extern void test_suite_utility(void);


static void all_tests(void) {
    test_suite_algorithm();
    test_suite_container();
    test_suite_iterator();
    test_suite_utility();
}

int main(int argc, char *argv[]) {
    /* We return !seatest_testrunner() because it returns 1 on success and
     * main should return 0 on success.
     */
    return !seatest_testrunner(argc, argv, all_tests, NULL, NULL);
}
