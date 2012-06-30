/*!
 * Unit tests for the pair template.
 *
 * @author Louis Dionne
 */

#include <nstl/pair.h>
#include <seatest.h>


#define pair_type nstl_pair(int, int)
NSTL_IMPLEMENT(NSTL_PAIR(int, int))

static void should_have_first_and_second_as_set(void)
{
    int first = 88;
    int second = 99;
    pair_type pair;
    nstl_init(pair_type)(&pair, first, second);
    assert_int_equal(pair.first, first);
    assert_int_equal(pair.second, second);
}

static void make_pair_should_be_equivalent_to_init(void)
{
    int first = 88;
    int second = 99;
    pair_type x, y;
    nstl_init(pair_type)(&x, first, second);
    y = nstl_make_pair(int, int)(first, second);
    assert_true(nstl_eq(pair_type)(x, y));
}

static void should_be_equal_when_first_and_second_are_equal(void)
{
    pair_type x, y;
    nstl_init(pair_type)(&x, 88, 99);
    nstl_init(pair_type)(&y, 88, 99);
    assert_true(nstl_eq(pair_type)(x, y));
    assert_true(nstl_eq(pair_type)(y, x));
}

static void should_not_be_equal_when_any_of_first_and_second_different(void)
{
    pair_type x, y;
    nstl_init(pair_type)(&x, 1, 1);
    nstl_init(pair_type)(&y, 0, 1);
    assert_false(nstl_eq(pair_type)(x, y));
    assert_false(nstl_eq(pair_type)(y, x));

    y.first = 1;
    y.second = 0;
    assert_false(nstl_eq(pair_type)(x, y));
    assert_false(nstl_eq(pair_type)(y, x));
}

static void should_not_be_different_when_first_and_second_are_equal(void)
{
    pair_type x, y;
    nstl_init(pair_type)(&x, 88, 99);
    nstl_init(pair_type)(&y, 88, 99);
    assert_false(nstl_ne(pair_type)(x, y));
    assert_false(nstl_ne(pair_type)(y, x));
}

static void should_be_different_when_any_of_first_and_second_are_different(void)
{
    pair_type x, y;
    nstl_init(pair_type)(&x, 1, 1);
    nstl_init(pair_type)(&y, 0, 1);
    assert_true(nstl_ne(pair_type)(x, y));
    assert_true(nstl_ne(pair_type)(y, x));

    y.first = 1;
    y.second = 0;
    assert_true(nstl_ne(pair_type)(x, y));
    assert_true(nstl_ne(pair_type)(y, x));
}

static void comparison_is_lexicographical(void)
{
    pair_type x = nstl_make_pair(int, int)(0, 1);
    pair_type y = nstl_make_pair(int, int)(1, 1);
    assert_true(nstl_lt(pair_type)(x, y));
    assert_true(nstl_le(pair_type)(x, y));
    assert_true(nstl_gt(pair_type)(y, x));
    assert_true(nstl_ge(pair_type)(y, x));

    assert_false(nstl_lt(pair_type)(y, x));
    assert_false(nstl_le(pair_type)(y, x));
    assert_false(nstl_gt(pair_type)(x, y));
    assert_false(nstl_ge(pair_type)(x, y));
}

static void should_be_le_and_ge_when_equal(void)
{
    pair_type x = nstl_make_pair(int, int)(1, 1);
    pair_type y = x;
    assert_true(nstl_le(pair_type)(x, y));
    assert_true(nstl_ge(pair_type)(x, y));
}

#undef pair_type


extern void test_fixture_pair(void)
{
    test_fixture_start();

    run_test(should_have_first_and_second_as_set);
    run_test(make_pair_should_be_equivalent_to_init);
    run_test(should_be_equal_when_first_and_second_are_equal);
    run_test(should_not_be_equal_when_any_of_first_and_second_different);
    run_test(should_not_be_different_when_first_and_second_are_equal);
    run_test(should_be_different_when_any_of_first_and_second_are_different);
    run_test(comparison_is_lexicographical);
    run_test(should_be_le_and_ge_when_equal);

    test_fixture_end();
}
