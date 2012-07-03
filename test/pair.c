/*!
 * Unit tests for the pair template.
 *
 * @author Louis Dionne
 */

#include <nstl/pair.h>
#include <seatest.h>


#define test_pair nstl_pair(int, int)
NSTL_IMPLEMENT(NSTL_PAIR(int, int))

static void should_have_first_and_second_as_set(void)
{
    int first = 88;
    int second = 99;
    test_pair pair;
    nstl_ctor(test_pair)(&pair, first, second);
    assert_int_equal(pair.first, first);
    assert_int_equal(pair.second, second);
}

static void make_pair_should_be_equivalent_to_init(void)
{
    int first = 88;
    int second = 99;
    test_pair x, y;
    nstl_ctor(test_pair)(&x, first, second);
    y = nstl_make_pair(int, int)(first, second);
    assert_true(nstl_eq(test_pair, test_pair)(x, y));
}

static void should_be_equal_when_first_and_second_are_equal(void)
{
    test_pair x, y;
    nstl_ctor(test_pair)(&x, 88, 99);
    nstl_copy_ctor(test_pair)(&y, x);
    assert_true(nstl_eq(test_pair, test_pair)(x, y));
    assert_true(nstl_eq(test_pair, test_pair)(y, x));
}

static void should_not_be_equal_when_any_of_first_and_second_different(void)
{
    test_pair x, y;
    nstl_ctor(test_pair)(&x, 1, 1);
    nstl_ctor(test_pair)(&y, 0, 1);
    assert_false(nstl_eq(test_pair, test_pair)(x, y));
    assert_false(nstl_eq(test_pair, test_pair)(y, x));

    y.first = 1;
    y.second = 0;
    assert_false(nstl_eq(test_pair, test_pair)(x, y));
    assert_false(nstl_eq(test_pair, test_pair)(y, x));
}

static void should_not_be_different_when_first_and_second_are_equal(void)
{
    test_pair x, y;
    nstl_ctor(test_pair)(&x, 88, 99);
    nstl_ctor(test_pair)(&y, 88, 99);
    assert_false(nstl_ne(test_pair, test_pair)(x, y));
    assert_false(nstl_ne(test_pair, test_pair)(y, x));
}

static void should_be_different_when_any_of_first_and_second_are_different(void)
{
    test_pair x, y;
    nstl_ctor(test_pair)(&x, 1, 1);
    nstl_ctor(test_pair)(&y, 0, 1);
    assert_true(nstl_ne(test_pair, test_pair)(x, y));
    assert_true(nstl_ne(test_pair, test_pair)(y, x));

    y.first = 1;
    y.second = 0;
    assert_true(nstl_ne(test_pair, test_pair)(x, y));
    assert_true(nstl_ne(test_pair, test_pair)(y, x));
}

static void comparison_is_lexicographical(void)
{
    test_pair x = nstl_make_pair(int, int)(0, 1);
    test_pair y = nstl_make_pair(int, int)(1, 1);
    assert_true(nstl_lt(test_pair, test_pair)(x, y));
    assert_true(nstl_le(test_pair, test_pair)(x, y));
    assert_true(nstl_gt(test_pair, test_pair)(y, x));
    assert_true(nstl_ge(test_pair, test_pair)(y, x));

    assert_false(nstl_lt(test_pair, test_pair)(y, x));
    assert_false(nstl_le(test_pair, test_pair)(y, x));
    assert_false(nstl_gt(test_pair, test_pair)(x, y));
    assert_false(nstl_ge(test_pair, test_pair)(x, y));
}

static void should_be_le_and_ge_when_equal(void)
{
    test_pair x = nstl_make_pair(int, int)(1, 1);
    test_pair y = x;
    assert_true(nstl_le(test_pair, test_pair)(x, y));
    assert_true(nstl_ge(test_pair, test_pair)(x, y));
}

#undef test_pair


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
