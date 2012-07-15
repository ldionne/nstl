/**
 * Macros to specify concept requirements and assert that
 * requirements are met.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_CONCEPT_BASE_H
#define NSTL_CONCEPT_BASE_H

#include <nstl/internal/config.h>
#include <nstl/internal/static_assert.h>

#include <chaos/preprocessor/stringize.h>


/**
 * Assert that a sequence of concept requirements are all met.
 *
 * When a requirement is not met, a preprocessor error is triggered with the
 * message that was provided when the requirement was specified.
 */
#if NSTL_CONFIG_CHECK_CONCEPT_REQUIREMENTS
#   define NSTL_CONCEPT(requirements) requirements
#else
#   define NSTL_CONCEPT(requirements) /* nothing */
#endif

/**
 * Specify a concept requirement.
 */
#define NSTL_CONCEPT_REQUIREMENT(requirement_, message)                        \
    NSTL_STATIC_ASSERT_PRIMITIVE(requirement_,                                 \
        CHAOS_PP_STRINGIZE(__FILE__:__LINE__: concept requirement not met:),   \
        message                                                                \
    )                                                                          \
/**/

#endif /* !NSTL_CONCEPT_BASE_H */
