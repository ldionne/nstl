/**
 * Specification of the @em copy_constructible concept.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_CONCEPT_COPY_CONSTRUCTIBLE_H
#define NSTL_CONCEPT_COPY_CONSTRUCTIBLE_H

#include <nstl/concept/base.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/type.h>


/**
 * A type is copy constructible if it has a copy constructor.
 */
#define NSTL_CONCEPT_COPY_CONSTRUCTIBLE(T)                                     \
NSTL_CONCEPT(                                                                  \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, copy_ctor), "missing copy constructor"                   \
    )                                                                          \
)                                                                              \
/**/

#endif /* !NSTL_CONCEPT_COPY_CONSTRUCTIBLE_H */
