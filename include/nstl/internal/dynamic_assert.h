/**
 * Macros to dynamically assert conditions.
 */

#ifndef NSTL_INTERNAL_DYNAMIC_ASSERT_H
#define NSTL_INTERNAL_DYNAMIC_ASSERT_H

#include <assert.h>


#define nstl_assert_true(e) assert(e)

#define nstl_assert_false(e) assert(!(e))

#endif /* !NSTL_INTERNAL_DYNAMIC_ASSERT_H */
