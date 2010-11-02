#ifndef garnet_crt__crt_string_h
#define garnet_crt__crt_string_h

#include <crt/_crt.h>


/**
 * CRT の strcpy_s 関数をエミュレートします。
 */
errno_t crt_strcpy(char* destination, size_t number_of_elements, const char* source);


/**
 * CRT の strncpy_s 関数をエミュレートします。
 */
errno_t crt_strncpy(char* destination, size_t number_of_elements, const char* source, size_t count);


/**
 * CRT の strcat_s 関数をエミュレートします。
 */
errno_t crt_strcat(char* destination, size_t number_of_elements, const char* source);


#endif  /* garnet_crt__crt_string_h */
