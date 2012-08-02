/**
 * Specification of the @em less_than_comparable concept.
 */

#ifndef NSTL_CONCEPT_LESS_THAN_COMPARABLE_H
#define NSTL_CONCEPT_LESS_THAN_COMPARABLE_H

#include <nstl/concept/base.h>
#include <nstl/internal/type.h>


/**
 * A type is less than comparable if it has the less than, greater than,
 * less or equal to, and greater or equal to operators.
 * operators.
 */
#define NSTL_CONCEPT_LESS_THAN_COMPARABLE(T)                                   \
NSTL_CONCEPT(                                                                  \
                                                                               \
NSTL_CONCEPT_REQUIREMENT(NSTL_ISSET(T, lt), "missing less than operator")      \
NSTL_CONCEPT_REQUIREMENT(NSTL_ISSET(T, gt), "missing greater than operator")   \
NSTL_CONCEPT_REQUIREMENT(                                                      \
    NSTL_ISSET(T, le), "missing less or equal to operator"                     \
)                                                                              \
NSTL_CONCEPT_REQUIREMENT(                                                      \
    NSTL_ISSET(T, ge), "missing greater or equal to operator"                  \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#endif /* !NSTL_CONCEPT_LESS_THAN_COMPARABLE_H */
