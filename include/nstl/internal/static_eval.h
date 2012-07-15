/**
 * Macros to statically evaluate expressions.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_STATIC_EVAL_H
#define NSTL_INTERNAL_STATIC_EVAL_H

#include <chaos/preprocessor/control/if.h>
#include <chaos/preprocessor/control/unless.h>
#include <chaos/preprocessor/control/when.h>


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
