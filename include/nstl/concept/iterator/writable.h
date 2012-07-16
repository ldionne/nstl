/**
 * Specification of the writable concept for iterators.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_CONCEPT_ITERATOR_WRITABLE_H
#define NSTL_CONCEPT_ITERATOR_WRITABLE_H

#include <nstl/concept/base.h>
#include <nstl/concept/copy_constructible.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/static_assert.h>
#include <nstl/internal/type.h>


/**
 * A type models the writable iterator concept if:
 *  - it fulfills the copy constructible concept
 *  - it is possible to assign to the result of dereferencing the iterator
 *
 * @note The @em value_type field is currently required in order to access
 *       the @em asg operator, so it must be provided.
 */
#define NSTL_CONCEPT_WRITABLE_ITERATOR(T)                                      \
NSTL_CONCEPT_COPY_CONSTRUCTIBLE(T)                                             \
                                                                               \
NSTL_CONCEPT(                                                                  \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, deref), "missing dereference operator"                   \
    )                                                                          \
    NSTL_STATIC_ASSERT(                                                        \
        NSTL_ISSET(T, value_type), "the value_type field must be provided in " \
                                   "order to access its assignment operator"   \
    )                                                                          \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(NSTL_GETF(T, value_type), asg),                             \
        "missing assignment operator to the value_type"                        \
    )                                                                          \
)                                                                              \
/**/

#endif /* !NSTL_CONCEPT_ITERATOR_WRITABLE_H */
