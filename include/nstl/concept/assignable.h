/**
 * Specification of the @em assignable concept.
 */

#ifndef NSTL_CONCEPT_ASSIGNABLE_H
#define NSTL_CONCEPT_ASSIGNABLE_H

#include <nstl/concept/base.h>
#include <nstl/internal/type.h>


/**
 * A type is assignable if it has a assignment operator
 * and a copy constructor.
 */
#define NSTL_CONCEPT_ASSIGNABLE(T)                                             \
NSTL_CONCEPT(                                                                  \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, asg), "missing assignment operator"                      \
    )                                                                          \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, copy_ctor), "missing copy constructor"                   \
    )                                                                          \
)                                                                              \
/**/

#endif /* !NSTL_CONCEPT_ASSIGNABLE_H */
