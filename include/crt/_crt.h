#ifndef garnet_crt__crt_h
#define garnet_crt__crt_h


//#ifdef GARNET_CRT_HAS_ERRNO_T_H
#   include <crt/errno_t.h>
//#endif  /* def GARNET_CRT_HAS_ERRNO_T_H */


#define     eos(str, index)         str[index] = '\0'
#define     str_truncate(str)       eos(str, 0)

#define     crt_max(x, y)           x > y? x: y
#define     crt_min(x, y)           x < y? x: y


#include "_guard_snip.h"


#endif  /* garnet_crt__crt_h */
