#ifndef garnet_crt_errno_h
#define garnet_crt_errno_h

#if !defined(_MSC_VER)
#   ifndef GARNET_CRT_DEFINE_ERRNO_T
typedef     int     errno_t;
#       define     GARNET_CRT_DEFINE_ERRNO_T
#   endif  /* ndef GARNET_CRT_DEFINE_ERRNO_T */
#endif  /* ndef GARNET_CRT_DEFINE_ERRNO_T */


#endif  /* garnet_crt_errno_h */
