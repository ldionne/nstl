/**
 * Wrapper over the standard C library.
 */

#ifndef NSTL_INTERNAL_STDLIB_WRAPPER_H
#define NSTL_INTERNAL_STDLIB_WRAPPER_H

#include <stddef.h>
#include <string.h>


#define nstl_memchr memchr
#define nstl_memcpy memcpy
#define nstl_memmove memmove
#define nstl_nullptr NULL

#endif /* !NSTL_INTERNAL_STDLIB_WRAPPER_H */
