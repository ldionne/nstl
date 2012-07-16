/**
 * Macros to statically assert conditions.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_STATIC_ASSERT_H
#define NSTL_INTERNAL_STATIC_ASSERT_H

#include <nstl/internal/config.h>

#include <chaos/preprocessor/cat.h>
#include <chaos/preprocessor/control/unless.h>
#include <chaos/preprocessor/stringize.h>


/**
 * This macro will trigger a preprocessor error if the condition is evaluated
 * to false. Only positive integral values are valid inputs to this macro.
 */
#if !NSTL_CONFIG_VARIADIC_MACROS

#define NSTL_STATIC_ASSERT_PRIMITIVE(condition, pre, message) \
    CHAOS_PP_UNLESS(condition)(NSTL_I_STATIC_ASSERTION_FAILURE(pre, message))

#define NSTL_I_STATIC_ASSERTION_FAILURE(pre, message) \
    CHAOS_PP_CAT(pre , message)

#else /* NSTL_CONFIG_VARIADIC_MACROS is true */

#define NSTL_STATIC_ASSERT_PRIMITIVE(condition, pre, ...)                      \
    CHAOS_PP_UNLESS(condition)(                                                \
        NSTL_I_STATIC_ASSERTION_FAILURE(pre, __VA_ARGS__)                      \
    )                                                                          \
/**/

#define NSTL_I_STATIC_ASSERTION_FAILURE(pre, ...) \
    CHAOS_PP_CAT(pre , __VA_ARGS__)

#endif /* NSTL_CONFIG_VARIADIC_MACROS */


#define NSTL_STATIC_ASSERT(condition, message)                                 \
    NSTL_STATIC_ASSERT_PRIMITIVE(condition,                                    \
        CHAOS_PP_STRINGIZE(__FILE__:__LINE__: failed static assertion:),       \
        message                                                                \
    )                                                                          \
/**/

#endif /* !NSTL_INTERNAL_STATIC_ASSERT_H */
