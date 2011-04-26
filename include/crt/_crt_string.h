/**
 * @file _crt_string.h
 * @since %create-timestamp%
 * 
 */
/*
    Copyright (c) 2010-2011 %full-author% %author-email%

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation; either version 3 of the License,
    or (at your option) any later version.

    This program is distributed in the hope that it will be useful, 
    but WITHOUT ANY WARRANTY; without even the implied warranty
    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program. If not, see <http://www.gnu.org/licenses/>.

    $Id _crt_string.h %timestamp% %author% $
 */
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
// Local Variables:
//   coding: shift_jis-dos
// End:
// _crt_string.h ends here
