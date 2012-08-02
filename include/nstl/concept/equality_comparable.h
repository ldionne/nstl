/**
 * Specification of the @em equality_comparable concept.
 */

#ifndef NSTL_CONCEPT_EQUALITY_COMPARABLE_H
#define NSTL_CONCEPT_EQUALITY_COMPARABLE_H

#include <nstl/concept/base.h>
#include <nstl/internal/type.h>


/**
 * A type is equality comparable if it has both the equality and inequality
 * operators.
 */
#define NSTL_CONCEPT_EQUALITY_COMPARABLE(T)                                    \
NSTL_CONCEPT(                                                                  \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, eq), "missing equality operator"                         \
    )                                                                          \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, neq), "missing inequality operator"                      \
    )                                                                          \
)                                                                              \
/**/

#endif /* !NSTL_CONCEPT_EQUALITY_COMPARABLE_H */
