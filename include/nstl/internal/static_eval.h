/**
 * Macros to statically evaluate expressions.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_STATIC_EVAL_H
#define NSTL_INTERNAL_STATIC_EVAL_H

#include <nstl/internal/config.h>

#include <chaos/preprocessor/cat.h>
#include <chaos/preprocessor/control/if.h>
#include <chaos/preprocessor/control/unless.h>
#include <chaos/preprocessor/control/when.h>


/**
 * This macro will trigger a preprocessor error if the condition is evaluated
 * to false. Only integral values are valid inputs to this macro.
 */
#if !NSTL_CONFIG_VARIADIC_MACROS

#define NSTL_STATIC_ASSERT(condition, message) \
    CHAOS_PP_UNLESS(condition)(NSTL_I_STATIC_ASSERTION_FAILURE(message))

#define NSTL_I_STATIC_ASSERTION_FAILURE(message) \
    CHAOS_PP_CAT(__FILE__:__LINE__: failed static assertion: , message)

#else /* NSTL_CONFIG_VARIADIC_MACROS is true */

#define NSTL_STATIC_ASSERT(condition, ...) \
    CHAOS_PP_UNLESS(condition)(NSTL_I_STATIC_ASSERTION_FAILURE(__VA_ARGS__))

#define NSTL_I_STATIC_ASSERTION_FAILURE(...) \
    CHAOS_PP_CAT(__FILE__:__LINE__: failed static assertion: , __VA_ARGS__)

#endif /* NSTL_CONFIG_VARIADIC_MACROS */

/**
 * This macro will expand to a macro that will expand to its first or its
 * second argument, depending on the boolean value of the expression that
 * is tested.
 */
#define NSTL_STATIC_IF(condition) CHAOS_PP_IF(condition)

/**
 * This expand will expand to a macro that will expand to its argument
 * when the tested expression has a boolean value of true, and else to
 * nothing.
 */
#define NSTL_STATIC_WHEN(condition) CHAOS_PP_WHEN(condition)

 /**
  * This expand will expand to a macro that will expand to its argument
  * when the tested expression has a boolean value of false, and else to
  * nothing.
  */
#define NSTL_STATIC_UNLESS(condition) CHAOS_PP_UNLESS(condition)

#endif /* !NSTL_INTERNAL_STATIC_EVAL_H */
