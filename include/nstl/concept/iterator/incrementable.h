/**
 * Specification of the incrementable concept for iterators.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_CONCEPT_ITERATOR_INCREMENTABLE_H
#define NSTL_CONCEPT_ITERATOR_INCREMENTABLE_H

#include <nstl/concept/assignable.h>
#include <nstl/concept/base.h>
#include <nstl/concept/copy_constructible.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/type.h>


/**
 * A type models the readable iterator concept if:
 *  - it fulfills the assignable concept
 *  - it fulfills the copy constructible concept
 *  - it can be postfix incremented
 *  - it can be prefix incremented
 *  - it can be dereferenced
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
        NSTL_ISSET(T, inc), "missing prefix increment operator"                \
    )                                                                          \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, inc_), "missing postfix increment operator"              \
    )                                                                          \
)                                                                              \
/**/

#endif /* !NSTL_CONCEPT_ITERATOR_INCREMENTABLE_H */
