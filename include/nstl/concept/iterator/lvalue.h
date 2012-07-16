/**
 * Specification of the lvalue concept for iterators.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_CONCEPT_ITERATOR_LVALUE_H
#define NSTL_CONCEPT_ITERATOR_LVALUE_H

#include <nstl/concept/base.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/static_assert.h>
#include <nstl/internal/type.h>


/**
 * A type models the lvalue iterator concept if:
 *  - dereferencing the iterator yields a constant pointer to the optionally
 *    constant value type of the iterator.
 */
#define NSTL_CONCEPT_LVALUE_ITERATOR(T)                                        \
NSTL_CONCEPT(                                                                  \
    NSTL_STATIC_ASSERT(                                                        \
        NSTL_ISSET(T, deref),                                                  \
        "an lvalue iterator must be dereferenceable"                           \
    )                                                                          \
)                                                                              \
/**/

#endif /* !NSTL_CONCEPT_ITERATOR_LVALUE_H */
