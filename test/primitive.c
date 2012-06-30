/*!
 * Unit tests for the primitive types.
 *
 * @author Louis Dionne
 */

#include <nstl/internal/primitive.h>
#include <seatest.h>
#include <stdlib.h>


NSTL_IMPLEMENT(NSTL_PRIMITIVE(int))

static void test_all_operators_are_like_normal_C_operators(void)
{
    int x, y, i;
    for (i = 0; i < 10; ++i) {
        x = random() + 1;
        y = random() + 1;
        assert_int_equal(nstl_add(int, int)(x, y), x + y);
        assert_int_equal(nstl_sub(int, int)(x, y), x - y);
        assert_int_equal(nstl_mul(int, int)(x, y), x * y);
        assert_int_equal(nstl_div(int, int)(x, y), x / y);
        assert_int_equal(nstl_mod(int, int)(x, y), x % y);
    }
}


extern void test_fixture_primitive(void)
{
    test_fixture_start();

    run_test(test_all_operators_are_like_normal_C_operators);

    test_fixture_end();
}
