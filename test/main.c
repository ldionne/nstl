/*!
 * Main for the unit tests of nstl.
 *
 * @author Louis Dionne
 */

#include <seatest.h>


extern void test_fixture_pair(void);
extern void test_fixture_primitive(void);
extern void test_suite_algorithm(void);
extern void test_fixture_vector(void);


static void all_tests(void)
{
    test_fixture_pair();
    test_fixture_primitive();
    test_suite_algorithm();
    test_fixture_vector();
}

int main(int argc, char *argv[])
{
    return seatest_testrunner(argc, argv, all_tests, NULL, NULL);
}
