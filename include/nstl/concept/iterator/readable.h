/**
 * Specification of the readable concept for iterators.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_CONCEPT_ITERATOR_READABLE_H
#define NSTL_CONCEPT_ITERATOR_READABLE_H

#include <nstl/concept/assignable.h>
#include <nstl/concept/base.h>
#include <nstl/concept/copy_constructible.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/type.h>


/**
 * A type models the readable iterator concept if:
 *  - it fulfills the assignable concept
 *  - it fulfills the copy constructible concept
 *  - it has a @em value_type field representing the type pointed to by
 *    the iterator
 *  - it is dereferenceable (when it is well-defined to do so)
 */
#define NSTL_CONCEPT_READABLE_ITERATOR(T)                                      \
NSTL_CONCEPT_ASSIGNABLE(T)                                                     \
NSTL_CONCEPT_COPY_CONSTRUCTIBLE(T)                                             \
                                                                               \
NSTL_CONCEPT(                                                                  \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, deref), "missing dereference operator"                   \
    )                                                                          \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, value_type), "missing value_type field"                  \
    )                                                                          \
)                                                                              \
/**/

#endif /* !NSTL_CONCEPT_ITERATOR_READABLE_H */
