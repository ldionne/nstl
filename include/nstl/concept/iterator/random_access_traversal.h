/**
 * Specification of the random access traversal concept for iterators.
 */

#ifndef NSTL_CONCEPT_ITERATOR_RANDOM_ACCESS_TRAVERSAL_H
#define NSTL_CONCEPT_ITERATOR_RANDOM_ACCESS_TRAVERSAL_H

#include <nstl/concept/base.h>
#include <nstl/concept/iterator/bidirectional_traversal.h>
#include <nstl/concept/less_than_comparable.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/type.h>


/**
 * A type models the random access traversal iterator concept if:
 *  - it fulfills the bidirectional traversal iterator concept
 *  - it fulfills the less than comparable concept
 *  - it can be added and substracted (and their assignment counterparts) with
 *    an object of type difference_type
 */
#define NSTL_CONCEPT_RANDOM_ACCESS_TRAVERSAL_ITERATOR(T)                       \
NSTL_CONCEPT_BIDIRECTIONAL_TRAVERSAL_ITERATOR(T)                               \
NSTL_CONCEPT_LESS_THAN_COMPARABLE(T)                                           \
                                                                               \
NSTL_CONCEPT(                                                                  \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, iadd), "missing addition assignment operator"            \
    )                                                                          \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, add), "missing addition operator"                        \
    )                                                                          \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, isub), "missing substraction assignment operator"        \
    )                                                                          \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, sub), "missing substraction operator"                    \
    )                                                                          \
)                                                                              \
/**/

#endif /* !NSTL_CONCEPT_ITERATOR_RANDOM_ACCESS_TRAVERSAL_H */
