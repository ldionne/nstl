/**
 * Specification of the swappable concept for iterators.
 */

#ifndef NSTL_CONCEPT_ITERATOR_SWAPPABLE_H
#define NSTL_CONCEPT_ITERATOR_SWAPPABLE_H

#include <nstl/concept/base.h>
#include <nstl/concept/copy_constructible.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/type.h>


/**
 * A type models the swappable iterator concept if:
 *  - it fulfills the copy constructible concept
 *  - it is possible to swap the pointed to values of two iterators by using
 *    the @em iter_swap function.
 */
#define NSTL_CONCEPT_WRITABLE_ITERATOR(T)                                      \
NSTL_CONCEPT_COPY_CONSTRUCTIBLE(T)                                             \
                                                                               \
NSTL_CONCEPT(                                                                  \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, iter_swap), "missing iter_swap function"                 \
    )                                                                          \
)                                                                              \
/**/

#endif /* !NSTL_CONCEPT_ITERATOR_SWAPPABLE_H */
