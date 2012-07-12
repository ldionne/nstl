/**
 * Unit tests for the primitive types.
 *
 * @author Louis Dionne
 */

/* Since the primitive types are so trivial to implement, time was not lost
 * writing __useless__ unit tests. The only unit test that is done here is
 * their instantiation, which makes sure that there are no compilation errors.
 */
#define NSTL_I_INSTANTIATE_PRIMITIVE(type) NSTL_INSTANTIATE(type)
#include <nstl/internal/primitive.h>
#undef NSTL_I_INSTANTIATE_PRIMITIVE

#include <seatest.h>


/* Dummy test so the test report shows something. */
static void test_it_compiled(void) {

}


extern void test_fixture_primitive(void) {
    test_fixture_start();

    run_test(test_it_compiled);

    test_fixture_end();
}
