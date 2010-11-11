#ifndef garnet_crt__crt_string_h
#define garnet_crt__crt_string_h

<<<<<<< HEAD
#ifdef GARNET_HAS_ERRNO_T_H
#   include <crt/errno_t.h>
#endif  /* def GARNET_HAS_ERRNO_T_H */


/**
 * CRT の strcpy_s をエミュレートします。
=======
#include <crt/_crt.h>


/**
 * CRT の strcpy_s 関数をエミュレートします。
>>>>>>> libgarnet-0.0_current
 */
errno_t crt_strcpy(char* destination, size_t number_of_elements, const char* source);


/**
<<<<<<< HEAD
 * CRT の strncpy_s をエミュレートします。
 */
errno_t crt_strcpy(char* destination, size_t number_of_elements, const char* source, size_t count);
=======
 * CRT の strncpy_s 関数をエミュレートします。
 */
errno_t crt_strncpy(char* destination, size_t number_of_elements, const char* source, size_t count);


/**
 * CRT の strcat_s 関数をエミュレートします。
 */
errno_t crt_strcat(char* destination, size_t number_of_elements, const char* source);
>>>>>>> libgarnet-0.0_current


#endif  /* garnet_crt__crt_string_h */
