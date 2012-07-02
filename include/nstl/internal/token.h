/*!
 * Macros to manipulate tokens and token strings.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_TOKEN_H
#define NSTL_INTERNAL_TOKEN_H

#include <chaos/preprocessor/facilities/split.h>
#include <chaos/preprocessor/facilities/expand.h>
#include <chaos/preprocessor/facilities/unbox.h>
#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/control/unless.h>
#include <chaos/preprocessor/control/if.h>
#include <chaos/preprocessor/detection/is_empty.h>
#include <chaos/preprocessor/algorithm/concat.h>
#include <chaos/preprocessor/string/core.h>


/*!
 * Given a token, return a representation containing its preprocessor string
 * representation as well as parenthesis necessary to make it a valid
 * preprocessor string character.
 *
 * @note In order for this macro to work properly, the NSTL_TOKEN_token
 *       macro must be defined to expand to the preprocessor string version
 *       of the token inside parenthesis.
 */
#define NSTL_TOKEN(token) NSTL_TOKEN_ ## token

#define NSTL_TOKEN_TO_STRING(token) CHAOS_PP_UNBOX(NSTL_TOKEN(token))


/*!
 * Return the first token of a token string.
 */
#define NSTL_TOKEN_STRING_HEAD(string) \
    NSTL_I_TOKEN_STRING_SPLIT(0, string)

/*!
 * Return the string with its first token removed.
 */
#define NSTL_TOKEN_STRING_TAIL(string) \
    NSTL_I_TOKEN_STRING_SPLIT(1, string)

/*!
 * Split a token string in two, keeping either its head or its tail.
 */
#define NSTL_I_TOKEN_STRING_SPLIT(zero_for_head_and_one_for_tail, string)      \
    CHAOS_PP_IF(zero_for_head_and_one_for_tail)(                               \
        NSTL_II_TOKEN_STRING_SPLIT(zero_for_head_and_one_for_tail, string),    \
        CHAOS_PP_CONCAT((CHAOS_PP_STRING)                                      \
            NSTL_II_TOKEN_STRING_SPLIT(zero_for_head_and_one_for_tail, string) \
        )                                                                      \
    )                                                                          \
/**/

#define NSTL_II_TOKEN_STRING_SPLIT(zero_for_head_and_one_for_tail, string)     \
    CHAOS_PP_SPLIT(zero_for_head_and_one_for_tail,                             \
     /* expands to: f i r s t  t o k e n , tail... */                          \
        CHAOS_PP_EXPAND(NSTL_III_TOKEN_STRING_SPLIT                            \
         /* expands to: (f i r s t  t o k e n) tail... */                      \
            NSTL_TOKEN_ ## string                                              \
        )                                                                      \
    )                                                                          \
/**/

#define NSTL_III_TOKEN_STRING_SPLIT(head) head, /* tail... */

/*!
 * Convert a token string into a sequence of tokens.
 */
#define NSTL_TOKEN_STRING_TO_SEQ(string) \
    NSTL_TOKEN_STRING_TO_SEQ_S(CHAOS_PP_STATE(), string)

#define NSTL_TOKEN_STRING_TO_SEQ_S(s, string)                                  \
    CHAOS_PP_EXPR_S(s)(NSTL_I_TOKEN_STRING_TO_SEQ(                             \
        CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), string                          \
    ))                                                                         \
/**/

#define NSTL_I_TOKEN_STRING_TO_SEQ_ID() NSTL_I_TOKEN_STRING_TO_SEQ
#define NSTL_I_TOKEN_STRING_TO_SEQ(_, s, string)                               \
    CHAOS_PP_UNLESS(CHAOS_PP_IS_EMPTY(string)) _(                              \
        (NSTL_TOKEN_STRING_HEAD _(string))                                     \
                                                                               \
        CHAOS_PP_UNLESS(CHAOS_PP_IS_EMPTY(NSTL_TOKEN_STRING_TAIL(string))) _(  \
            CHAOS_PP_EXPR_S _(s)(                                              \
                NSTL_I_TOKEN_STRING_TO_SEQ_ID _() (CHAOS_PP_OBSTRUCT _(),      \
                    CHAOS_PP_NEXT(s), NSTL_TOKEN_STRING_TAIL(string)           \
                )                                                              \
            )                                                                  \
        )                                                                      \
    )                                                                          \
/**/

#endif /* !NSTL_INTERNAL_TOKEN_H */
