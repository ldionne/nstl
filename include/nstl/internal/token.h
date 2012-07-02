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
#include <chaos/preprocessor/algorithm/concat.h>
#include <chaos/preprocessor/string/core.h>
#include <chaos/preprocessor/control/if.h>


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

#endif /* !NSTL_INTERNAL_TOKEN_H */
