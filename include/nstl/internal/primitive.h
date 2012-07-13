/**
 * Master header including the definition of all C primitive data types.
 *
 * When the NSTL_I_INSTANTIATE_PRIMITIVE flag is set, including the files
 * below will trigger the instantiation of the primitive types defined
 * in each of them.
 *
 * We use this by setting the flag to 1 on the command line and then
 * preprocessing this file. Then, with a few lines of bash, everything
 * between the two ``------'' lines is kept and written to
 * ``nstl/internal/primitive.i''. This precomputes the primitive types,
 * allowing for a great speedup of the compilation time.
 *
 * @author Louis Dionne
 */

/* If we are not generating the primitives, it should be already generated
 * so we include it and get all the definitions for free.
 */
#if !NSTL_I_INSTANTIATE_PRIMITIVE

#   ifndef NSTL_INTERNAL_PRIMITIVE_H
#   define NSTL_INTERNAL_PRIMITIVE_H

#       include <nstl/internal/boolean.h>
#       include <nstl/internal/floating_point.h>
#       include <nstl/internal/integral.h>

#       include <nstl/internal/primitive.i>

#   endif /* !NSTL_INTERNAL_PRIMITIVE_H */

#else /* NSTL_I_INSTANTIATE_PRIMITIVE */

/* First, include the files containing the definitions needed
 * to generate the instantiations.
 */
#   undef NSTL_I_INSTANTIATE_PRIMITIVE
#   include <nstl/internal/boolean.h>
#   include <nstl/internal/floating_point.h>
#   include <nstl/internal/integral.h>

/* Then, instantiate the primitive types. */
#   define NSTL_I_INSTANTIATE_PRIMITIVE 1

------------------------------------------------------------------------------

#   include <nstl/internal/boolean.h>
#   include <nstl/internal/floating_point.h>
#   include <nstl/internal/integral.h>

------------------------------------------------------------------------------

/* Since we only ever want to generate them once, unset the flag. */
#   undef NSTL_I_INSTANTIATE_PRIMITIVE

#endif /* !NSTL_I_INSTANTIATE_PRIMITIVE */
