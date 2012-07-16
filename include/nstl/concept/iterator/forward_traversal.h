/**
 * Specification of the forward traversal concept for iterators.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_CONCEPT_ITERATOR_FORWARD_TRAVERSAL_H
#define NSTL_CONCEPT_ITERATOR_FORWARD_TRAVERSAL_H

#include <nstl/concept/base.h>
#include <nstl/concept/default_constructible.h>
#include <nstl/concept/iterator/single_pass.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/type.h>


/**
 * A type models the forward traversal iterator concept if:
 *  - it fulfills the default constructible concept
 *  - it fulfills the single pass iterator concept
 */
#define NSTL_CONCEPT_FORWARD_TRAVERSAL_ITERATOR(T)                             \
NSTL_CONCEPT_DEFAULT_CONSTRUCTIBLE(T)                                          \
NSTL_CONCEPT_SINGLE_PASS_ITERATOR(T)                                           \
/**/

#endif /* !NSTL_CONCEPT_ITERATOR_FORWARD_TRAVERSAL_H */
