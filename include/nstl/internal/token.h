/**
 * Macros to manipulate tokens and token strings.
 *
 * @note This was taken from the Chaos preprocessor library. All credit goes
 *       to the original authors. The reason I use a copy of their string/core
 *       operations is that I needed to be able to define tokens using the
 *       NSTL_TOKEN_ construct.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_TOKEN_H
#define NSTL_INTERNAL_TOKEN_H

#include <chaos/preprocessor/algorithm/concat.h>
#include <chaos/preprocessor/cat.h>
#include <chaos/preprocessor/config.h>
#include <chaos/preprocessor/control/iif.h>
#include <chaos/preprocessor/control/inline_unless.h>
#include <chaos/preprocessor/control/inline_when.h>
#include <chaos/preprocessor/detection/is_empty.h>
#include <chaos/preprocessor/detection/is_nullary.h>
#include <chaos/preprocessor/facilities/empty.h>
#include <chaos/preprocessor/facilities/expand.h>
#include <chaos/preprocessor/facilities/split.h>
#include <chaos/preprocessor/facilities/unbox.h>
#include <chaos/preprocessor/logical/compl.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/string/core.h>


/**
 * Given a token, return a representation containing its preprocessor string
 * representation as well as parenthesis necessary to make it a valid
 * preprocessor string character.
 *
 * @note In order for this macro to work properly, the NSTL_TOKEN_token
 *       macro must be defined to expand to the preprocessor string version
 *       of the token inside parenthesis.
 */
#define NSTL_TOKEN(token) CHAOS_PP_CAT(NSTL_TOKEN_, token)

#define NSTL_TOKEN_TO_STRING(token) CHAOS_PP_UNBOX(NSTL_TOKEN(token))

/**
 * Represents an empty token string.
 */
#define NSTL_TOKEN_STRING_NIL() ()

/**
 * Add a token to the beginning of a token string.
 */
#define NSTL_TOKEN_STRING_CONS(string, x)                                      \
    x CHAOS_PP_INLINE_WHEN(NSTL_TOKEN_STRING_IS_NIL(string))(                  \
        CHAOS_PP_EMPTY                                                         \
    ) string                                                                   \
/**/

/**
 * Return the first token of a token string.
 */
#define NSTL_TOKEN_STRING_HEAD(string)                                         \
    CHAOS_PP_IIF(NSTL_TOKEN_STRING_IS_NIL(string))(                            \
        NSTL_I_TOKEN_STRING_NIL_INPUT_EXCEPTION(!),                            \
                                                                               \
        CHAOS_PP_CONCAT((CHAOS_PP_STRING)                                      \
            CHAOS_PP_SPLIT(0,                                                  \
                CHAOS_PP_EXPAND(                                               \
                    NSTL_I_TOKEN_STRING_HEAD                                   \
                        CHAOS_PP_PRIMITIVE_CAT(NSTL_TOKEN_, string)            \
                )                                                              \
            )                                                                  \
        )                                                                      \
    )                                                                          \
/**/
#define NSTL_I_TOKEN_STRING_HEAD(x) x, ~

/**
 * Return the string with its head removed.
 */
#define NSTL_TOKEN_STRING_TAIL(string)                                         \
    CHAOS_PP_IIF(NSTL_TOKEN_STRING_IS_NIL(string))(                            \
        NSTL_I_TOKEN_STRING_NIL_INPUT_EXCEPTION(!),                            \
                                                                               \
        NSTL_II_TOKEN_STRING_TAIL(CHAOS_PP_SPLIT(1,                            \
            CHAOS_PP_EXPAND(                                                   \
                NSTL_I_TOKEN_STRING_TAIL                                       \
                    CHAOS_PP_PRIMITIVE_CAT(NSTL_TOKEN_, string)                \
            )                                                                  \
        ))                                                                     \
    )                                                                          \
/**/

/**
 * Return the string with its head removed.
 *
 * The difference between this and @em NSTL_TOKEN_STRING_TAIL() is that this
 * macro has undefined behavior if the string does not have a length of at
 * least 2 tokens, but it does not require the tail of the string to be a
 * valid token string.
 */
#define NSTL_TOKEN_STRING_TAIL_UNSAFE(string)                                  \
     CHAOS_PP_IIF(NSTL_TOKEN_STRING_IS_NIL(string))(                           \
         NSTL_I_TOKEN_STRING_NIL_INPUT_EXCEPTION(!),                           \
                                                                               \
         CHAOS_PP_SPLIT(1,                                                     \
             CHAOS_PP_EXPAND(                                                  \
                 NSTL_I_TOKEN_STRING_TAIL_UNSAFE                               \
                     CHAOS_PP_PRIMITIVE_CAT(NSTL_TOKEN_, string)               \
             )                                                                 \
         )                                                                     \
     )                                                                         \
 /**/

#define NSTL_I_TOKEN_STRING_TAIL_UNSAFE(x) x,
#define NSTL_I_TOKEN_STRING_TAIL(x) x, ()
#define NSTL_II_TOKEN_STRING_TAIL(r)                                           \
    CHAOS_PP_INLINE_UNLESS(CHAOS_PP_IS_EMPTY(CHAOS_PP_EMPTY r))(               \
        CHAOS_PP_EMPTY                                                         \
    ) r                                                                        \
/**/

/**
 * Return whether a token string has tokens in it.
 */
#define NSTL_TOKEN_STRING_IS_CONS(string) \
    CHAOS_PP_COMPL(NSTL_TOKEN_STRING_IS_NIL(string))

/**
 * Return whether a token string is empty.
 */
#define NSTL_TOKEN_STRING_IS_NIL(string) CHAOS_PP_IS_NULLARY(string())

/**
 * Convert a token string into a sequence of tokens.
 */
#define NSTL_TOKEN_STRING_TO_SEQ(string) \
    NSTL_TOKEN_STRING_TO_SEQ_S(CHAOS_PP_STATE(), string)

#define NSTL_TOKEN_STRING_TO_SEQ_S(s, string)                                  \
    CHAOS_PP_IIF(NSTL_TOKEN_STRING_IS_NIL(string))(                            \
        NSTL_I_TOKEN_STRING_NIL_INPUT_EXCEPTION(!),                            \
                                                                               \
        CHAOS_PP_EXPR_S(s)(NSTL_I_TOKEN_STRING_TO_SEQ(                         \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), string                      \
        ))                                                                     \
    )                                                                          \
/**/

#define NSTL_I_TOKEN_STRING_NIL_INPUT_EXCEPTION()

#define NSTL_I_TOKEN_STRING_TO_SEQ_ID() NSTL_I_TOKEN_STRING_TO_SEQ
#define NSTL_I_TOKEN_STRING_TO_SEQ(_, s, string)                               \
    (NSTL_TOKEN_STRING_HEAD(string))                                           \
                                                                               \
    NSTL_II_TOKEN_STRING_TO_SEQ_CONTINUE(CHAOS_PP_OBSTRUCT(), s,               \
        NSTL_TOKEN_STRING_TAIL(string)                                         \
    )                                                                          \
/**/

#define NSTL_II_TOKEN_STRING_TO_SEQ_CONTINUE(_, s, tail)                       \
    CHAOS_PP_INLINE_UNLESS(NSTL_TOKEN_STRING_IS_NIL(tail)) _(                  \
        CHAOS_PP_EXPR_S _(s)(                                                  \
            NSTL_I_TOKEN_STRING_TO_SEQ_ID _() (CHAOS_PP_OBSTRUCT _(),          \
                CHAOS_PP_NEXT(s), tail                                         \
            )                                                                  \
        )                                                                      \
    )                                                                          \
/**/

#endif /* !NSTL_INTERNAL_TOKEN_H */
