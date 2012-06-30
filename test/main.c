/*!
 * Main for the unit tests of nstl.
 *
 * @author Louis Dionne
 */

#include <seatest.h>


extern void test_fixture_pair(void);
extern void test_fixture_primitive(void);


static void all_tests(void)
{
    test_fixture_pair();
    test_fixture_primitive();
}

int main(int argc, char const *argv[])
{
    return run_tests(all_tests);
}
