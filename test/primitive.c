/*!
 * Unit tests for the primitive types.
 *
 * @author Louis Dionne
 */

#include <nstl/primitive.h>
#include <seatest.h>


/* Since the primitive types are so trivial to implement, time was not lost
 * writing __useless__ unit tests. The only unit test that is done here is
 * their instantiation, which makes sure that there are no compilation errors.
 */
NSTL_INSTANTIATE(NSTL_CHAR)
NSTL_INSTANTIATE(NSTL_SHORT)
NSTL_INSTANTIATE(NSTL_INT)
NSTL_INSTANTIATE(NSTL_LONG)

NSTL_INSTANTIATE(NSTL_FLOAT)
NSTL_INSTANTIATE(NSTL_DOUBLE)


/* Dummy test so the test report shows something. */
static void test_it_compiled(void)
{

}


extern void test_fixture_primitive(void)
{
    test_fixture_start();

    run_test(test_it_compiled);

    test_fixture_end();
}
