/**
 * Specification of the @em default_constructible concept.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_CONCEPT_DEFAULT_CONSTRUCTIBLE_H
#define NSTL_CONCEPT_DEFAULT_CONSTRUCTIBLE_H

#include <nstl/concept/base.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/type.h>


/**
 * A type is default constructible if it has a default constructor taking
 * no arguments.
 */
#define NSTL_CONCEPT_DEFAULT_CONSTRUCTIBLE(T)                                  \
NSTL_CONCEPT(                                                                  \
    NSTL_CONCEPT_REQUIREMENT(                                                  \
        NSTL_ISSET(T, def_ctor), "missing default constructor"                 \
    )                                                                          \
)                                                                              \
/**/

#endif /* !NSTL_CONCEPT_DEFAULT_CONSTRUCTIBLE_H */
