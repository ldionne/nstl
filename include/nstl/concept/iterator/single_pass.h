/**
 * Specification of the single pass concept for iterators.
 */

#ifndef NSTL_CONCEPT_ITERATOR_SINGLE_PASS_H
#define NSTL_CONCEPT_ITERATOR_SINGLE_PASS_H

#include <nstl/concept/base.h>
#include <nstl/concept/equality_comparable.h>
#include <nstl/concept/iterator/incrementable.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/type.h>


/**
 * A type models the single pass iterator concept if:
 *  - it fulfills the incrementable iterator concept
 *  - it fulfills the equality comparable concept
 *  - it has a @em difference_type field representing the distance
 *    between iterators.
 */
#define NSTL_CONCEPT_SINGLE_PASS_ITERATOR(T)                                   \
NSTL_CONCEPT_INCREMENTABLE_ITERATOR(T)                                         \
NSTL_CONCEPT_EQUALITY_COMPARABLE(T)                                            \
                                                                               \
NSTL_CONCEPT(                                                                  \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, difference_type), "missing difference_type field"        \
    )                                                                          \
)                                                                              \
/**/

#endif /* !NSTL_CONCEPT_ITERATOR_SINGLE_PASS_H */
