#ifndef garnet_crt__crt_string_h
#define garnet_crt__crt_string_h

#ifdef GARNET_HAS_ERRNO_T_H
#   include <crt/errno_t.h>
#endif  /* def GARNET_HAS_ERRNO_T_H */


/**
 * CRT の strcpy_s をエミュレートします。
 */
errno_t crt_strcpy(char* destination, size_t number_of_elements, const char* source);


/**
 * CRT の strncpy_s をエミュレートします。
 */
errno_t crt_strcpy(char* destination, size_t number_of_elements, const char* source, size_t count);


#endif  /* garnet_crt__crt_string_h */
