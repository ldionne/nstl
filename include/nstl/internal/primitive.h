/*!
 * Implementation of C primitive types.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_PRIMITIVE_H
#define NSTL_INTERNAL_PRIMITIVE_H

#include <nstl/internal/floating_point.h>
#include <nstl/internal/integral.h>


#define NSTL_CHAR NSTL_INTEGRAL(char)
#define NSTL_SHORT NSTL_INTEGRAL(short)
#define NSTL_INT NSTL_INTEGRAL(int)
#define NSTL_LONG NSTL_INTEGRAL(long)

#define NSTL_DOUBLE NSTL_FLOATING_POINT(double)
#define NSTL_FLOAT NSTL_FLOATING_POINT(float)

#endif /* !NSTL_INTERNAL_PRIMITIVE_H */
