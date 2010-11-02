#ifndef garnet_crt__crt_string_h
#define garnet_crt__crt_string_h

#include <crt/_crt.h>


/**
 * CRT �� strcpy_s �֐����G�~�����[�g���܂��B
 */
errno_t crt_strcpy(char* destination, size_t number_of_elements, const char* source);


/**
 * CRT �� strncpy_s �֐����G�~�����[�g���܂��B
 */
errno_t crt_strncpy(char* destination, size_t number_of_elements, const char* source, size_t count);


/**
 * CRT �� strcat_s �֐����G�~�����[�g���܂��B
 */
errno_t crt_strcat(char* destination, size_t number_of_elements, const char* source);


#endif  /* garnet_crt__crt_string_h */
