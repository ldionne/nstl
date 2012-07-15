/**
 * Macros to specify concept requirements and assert that
 * requirements are met.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_CONCEPT_H
#define NSTL_INTERNAL_CONCEPT_H

#include <nstl/internal/static_assert.h>

#include <chaos/preprocessor/stringize.h>


/**
 * Assert that a sequence of concept requirements are all met.
 *
 * When a requirement is not met, a preprocessor error is triggered with the
 * message that was provided when the requirement was specified.
 */
#define NSTL_CONCEPT(requirements) requirements

/**
 * Specify a concept requirement.
 */
#define NSTL_CONCEPT_REQUIREMENT(requirement_, message)                        \
    NSTL_STATIC_ASSERT_PRIMITIVE(requirement_,                                 \
        CHAOS_PP_STRINGIZE(__FILE__:__LINE__: concept requirement not met:),   \
        message                                                                \
    )                                                                          \
/**/

#endif /* !NSTL_INTERNAL_CONCEPT_H */
