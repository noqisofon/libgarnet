#ifndef garnet_crt__crt_string_h
#define garnet_crt__crt_string_h

<<<<<<< HEAD
#ifdef GARNET_HAS_ERRNO_T_H
#   include <crt/errno_t.h>
#endif  /* def GARNET_HAS_ERRNO_T_H */


/**
 * CRT �� strcpy_s ���G�~�����[�g���܂��B
=======
#include <crt/_crt.h>


/**
 * CRT �� strcpy_s �֐����G�~�����[�g���܂��B
>>>>>>> libgarnet-0.0_current
 */
errno_t crt_strcpy(char* destination, size_t number_of_elements, const char* source);


/**
<<<<<<< HEAD
 * CRT �� strncpy_s ���G�~�����[�g���܂��B
 */
errno_t crt_strcpy(char* destination, size_t number_of_elements, const char* source, size_t count);
=======
 * CRT �� strncpy_s �֐����G�~�����[�g���܂��B
 */
errno_t crt_strncpy(char* destination, size_t number_of_elements, const char* source, size_t count);


/**
 * CRT �� strcat_s �֐����G�~�����[�g���܂��B
 */
errno_t crt_strcat(char* destination, size_t number_of_elements, const char* source);
>>>>>>> libgarnet-0.0_current


#endif  /* garnet_crt__crt_string_h */
