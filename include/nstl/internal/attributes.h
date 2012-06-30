/*!
 * Declaration of nstl instructions and attributes.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_ATTRIBUTES_H
#define NSTL_INTERNAL_ATTRIBUTES_H

#include <nstl/internal/type.h>

#include <chaos/preprocessor/seq/fold_left.h>
#include <joy/seq/remove_if.h>
#include <joy/seq/append.h>
#include <joy/string/eq.h>
#include <joy/pair.h>


#define NSTL_TOKEN_drop (d r o p)
#define NSTL_INSTRUCTION_drop(s, self, attr)                                   \
    JOY_SEQ_REMOVE_IF_S(s,                                                     \
        NSTL_I_IS_SAME_ATTR, self, NSTL_TOKEN_TO_STRING(attr)                  \
    )                                                                          \
/**/

#define NSTL_I_IS_SAME_ATTR(s, attr_impl, attr)                                \
    JOY_STRING_EQ_S(s,                                                         \
        JOY_PAIR_FIRST(attr_impl), attr                                        \
    )                                                                          \
/**/

#define NSTL_TOKEN_implement (i m p l e m e n t)
#define NSTL_INSTRUCTION_implement(s, self, attr, implementation)              \
    NSTL_I_INSTRUCTION_implement(s,                                            \
        CHAOS_PP_IF(JOY_SEQ_CONTAINS_S(s,                                      \
            NSTL_I_IS_SAME_ATTR, self, NSTL_TOKEN_TO_STRING(attr)              \
        ))                                                                     \
           (NSTL_INSTRUCTION_drop(s, self, attr), self),                       \
            attr,                                                              \
            implementation                                                     \
    )                                                                          \
/**/

#define NSTL_I_INSTRUCTION_implement(s, self, attr, implementation)            \
    JOY_SEQ_APPEND(                                                            \
        JOY_PAIR(NSTL_TOKEN_TO_STRING(attr), implementation), self             \
    )                                                                          \
/**/

#define NSTL_TOKEN_inherit (i n h e r i t)
#define NSTL_INSTRUCTION_inherit(s, self, base_type)                           \
    CHAOS_PP_EXPR_S(s)(                                                        \
        CHAOS_PP_SEQ_FOLD_LEFT_S(s,                                            \
            NSTL_I_INSTRUCTION_inherit, base_type, self                        \
        )                                                                      \
    )                                                                          \
/**/

#define NSTL_I_INSTRUCTION_inherit(s, attr_impl, self)                         \
    NSTL_INSTRUCTION_implement(s,                                              \
        self,                                                                  \
        /* rebuild the attribute name as a token for INSTRUCTION_implement. */ \
        JOY_STRING_CAT_S(s, JOY_PAIR_FIRST(attr_impl)),                        \
        JOY_PAIR_SECOND(attr_impl)                                             \
    )                                                                          \
/**/

#endif /* !NSTL_INTERNAL_ATTRIBUTES_H */
