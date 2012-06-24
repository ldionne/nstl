/*!
 * Unit tests for the pair template.
 *
 * @author Louis Dionne
 */

#include <nstl/pair.h>


#define pair_type nstl_pair(int, int)
NSTL_IMPLEMENT(NSTL_PAIR(int, int))

static void should_have_first_and_second_as_set(void)
{
    int first = 88;
    int second = 99;
    pair_type pair;
    nstl_init(pair_type)(&pair, first, second);
    assert(pair.first == first);
    assert(pair.second == second);
}

static void make_pair_should_be_equivalent_to_init(void)
{
    int first = 88;
    int second = 99;
    pair_type x, y;
    nstl_init(pair_type)(&x, first, second);
    y = nstl_make_pair(int, int)(first, second);
    assert(nstl_eq(pair_type)(x, y));
}

static void should_be_equal_when_first_and_second_are_equal(void)
{
    pair_type x, y;
    nstl_init(pair_type)(&x, 88, 99);
    nstl_init(pair_type)(&y, 88, 99);
    assert(nstl_eq(pair_type)(x, y));
    assert(nstl_eq(pair_type)(y, x));
}

static void should_not_be_equal_when_any_of_first_and_second_different(void)
{
    pair_type x, y;
    nstl_init(pair_type)(&x, 1, 1);
    nstl_init(pair_type)(&y, 0, 1);
    assert(!nstl_eq(pair_type)(x, y));
    assert(!nstl_eq(pair_type)(y, x));

    y.first = 1;
    y.second = 0;
    assert(!nstl_eq(pair_type)(x, y));
    assert(!nstl_eq(pair_type)(y, x));
}

static void should_not_be_different_when_first_and_second_are_not(void)
{
    pair_type x, y;
    nstl_init(pair_type)(&x, 88, 99);
    nstl_init(pair_type)(&y, 88, 99);
    assert(!nstl_ne(pair_type)(x, y));
    assert(!nstl_ne(pair_type)(y, x));
}

static void should_be_different_when_any_of_first_and_second_are_different(void)
{
    pair_type x, y;
    nstl_init(pair_type)(&x, 1, 1);
    nstl_init(pair_type)(&y, 0, 1);
    assert(nstl_ne(pair_type)(x, y));
    assert(nstl_ne(pair_type)(y, x));

    y.first = 1;
    y.second = 0;
    assert(nstl_ne(pair_type)(x, y));
    assert(nstl_ne(pair_type)(y, x));
}

static void comparison_is_lexicographical(void)
{
    pair_type x = nstl_make_pair(int, int)(0, 1);
    pair_type y = nstl_make_pair(int, int)(1, 1);
    assert(nstl_lt(pair_type)(x, y));
    assert(nstl_le(pair_type)(x, y));
    assert(nstl_gt(pair_type)(y, x));
    assert(nstl_ge(pair_type)(y, x));

    assert(!nstl_lt(pair_type)(y, x));
    assert(!nstl_le(pair_type)(y, x));
    assert(!nstl_gt(pair_type)(x, y));
    assert(!nstl_ge(pair_type)(x, y));
}

static void le_and_ge_are_true_when_equal_as_well(void)
{
    pair_type x = nstl_make_pair(int, int)(1, 1);
    pair_type y = x;
    assert(nstl_le(pair_type)(x, y));
    assert(nstl_ge(pair_type)(x, y));
}

#undef pair_type

extern void test_pair(void)
{
    should_have_first_and_second_as_set();
    make_pair_should_be_equivalent_to_init();
    should_be_equal_when_first_and_second_are_equal();
    should_not_be_equal_when_any_of_first_and_second_different();
    should_not_be_different_when_first_and_second_are_not();
    should_be_different_when_any_of_first_and_second_are_different();
    comparison_is_lexicographical();
    le_and_ge_are_true_when_equal_as_well();
}
