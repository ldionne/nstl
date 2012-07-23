/**
 * This file defines a macro to generate mangled names for helper functions
 * inside template implementations.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_HELPER_H
#define NSTL_INTERNAL_HELPER_H

#include <chaos/preprocessor/cat.h>


/**
 * Generate a mangled name for an helper function.
 */
#define nstl_helper(base_name, helper_func) \
    CHAOS_PP_CAT(CHAOS_PP_CAT(base_name, _helper_), helper_func)

#endif /* !NSTL_INTERNAL_HELPER_H */
