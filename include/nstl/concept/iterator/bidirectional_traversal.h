/**
 * Specification of the bidirectional traversal concept for iterators.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_CONCEPT_ITERATOR_BIDIRECTIONAL_TRAVERSAL_H
#define NSTL_CONCEPT_ITERATOR_BIDIRECTIONAL_TRAVERSAL_H

#include <nstl/concept/base.h>
#include <nstl/concept/iterator/forward_traversal.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/type.h>


/**
 * A type models the bidirectional traversal iterator concept if:
 *  - it fulfills the forward traversal iterator concept
 */
#define NSTL_CONCEPT_BIDIRECTIONAL_TRAVERSAL_ITERATOR(T)                       \
NSTL_CONCEPT_FORWARD_TRAVERSAL_ITERATOR(T)                                     \
                                                                               \
NSTL_CONCEPT(                                                                  \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, dec), "missing prefix decrement operator"                \
    )                                                                          \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, dec_), "missing postfix decrement operator"              \
    )                                                                          \
)                                                                              \
/**/

#endif /* !NSTL_CONCEPT_ITERATOR_BIDIRECTIONAL_TRAVERSAL_H */
