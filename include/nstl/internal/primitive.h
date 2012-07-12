/**
 * Master header including the definition of all C primitive data types.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_PRIMITIVE_H
#define NSTL_INTERNAL_PRIMITIVE_H

/* The @em NSTL_I_INSTANTIATE_PRIMITIVE() macro is used because it could be
 * useful to use pre-preprocessed headers in the future. If that happens,
 * controling the instantiation of primitive data types with a single macro
 * will be easier than changing the macros for all primitive data types.
 */
#ifndef NSTL_I_INSTANTIATE_PRIMITIVE
#   define NSTL_I_UNDEF_INSTANTIATE_PRIMITIVE
#   define NSTL_I_INSTANTIATE_PRIMITIVE(type)
#endif

#include <nstl/internal/boolean.h>
#include <nstl/internal/floating_point.h>
#include <nstl/internal/integral.h>

#ifdef NSTL_I_UNDEF_INSTANTIATE_PRIMITIVE
#   undef NSTL_I_INSTANTIATE_PRIMITIVE
#   undef NSTL_I_UNDEF_INSTANTIATE_PRIMITIVE
#endif

#endif /* !NSTL_INTERNAL_PRIMITIVE_H */
