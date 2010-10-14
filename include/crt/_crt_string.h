#ifndef garnet_crt__crt_string_h
#define garnet_crt__crt_string_h

#ifdef GARNET_HAS_ERRNO_T_H
#   include <crt/errno_t.h>
#endif  /* def GARNET_HAS_ERRNO_T_H */


/**
 * CRT �� strcpy_s ���G�~�����[�g���܂��B
 */
errno_t crt_strcpy(char* destination, size_t number_of_elements, const char* source);


/**
 * CRT �� strncpy_s ���G�~�����[�g���܂��B
 */
errno_t crt_strcpy(char* destination, size_t number_of_elements, const char* source, size_t count);


#endif  /* garnet_crt__crt_string_h */
