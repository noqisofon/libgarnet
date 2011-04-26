/* -*- encoding: utf-8; -*- */
/**
 * @file _crt_string.c
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

    $Id _crt_string.c %timestamp% %author% $
 */
#include <stdafx.h>
#include <errno.h>
#include <string.h>

#include <crt/_guard_snip.h>
#include <crt/_crt_string.h>


errno_t crt_strcpy(char* destination, size_t number_of_elements, const char* source)
{
    size_t  i, dst_len, src_len;

    GARNET_VALIDATE_RETURN_ERRCODE(!destination, EINVAL);
    GARNET_VALIDATE_STRTRUNCATE_RETURN_ERRCODE(!source || number_of_elements == 0, EINVAL, destination);
    dst_len = strlen( destination );
    GARNET_VALIDATE_STRTRUNCATE_RETURN_ERRCODE(dst_len < number_of_elements, EINVAL, destination);

    src_len = strlen( source );
    for ( i = 0; i < number_of_elements; ++ i ) {
        if ( i < src_len )
            destination[i]  = source[i];
        else
            break;
    }
    eos(destination, i);

    return 0;
}


errno_t crt_strncpy(char* destination, size_t number_of_elements, const char* source, size_t count)
{
    size_t  i, dst_len, src_len;

    dst_len     = strlen( destination );
    src_len = crt_min(strlen( source ), count);

    GARNET_VALIDATE_RETURN_ERRCODE(!destination || !source || number_of_elements == 0, EINVAL);
    GARNET_VALIDATE_STRTRUNCATE_RETURN_ERRCODE(dst_len < number_of_elements, EINVAL, destination);

    for ( i = 0; i < number_of_elements; ++ i ) {
        if ( i < src_len )
            destination[i]  = source[i];
        else
            eos(destination, i);
    }
    eos(destination, i);

    return 0;
}


errno_t crt_strcat(char* destination, size_t number_of_elements, const char* source)
{
    char    *p  = NULL, *dst_last;
    size_t  i, dst_len, src_len;

    dst_len     = strlen( destination );
    src_len     = strlen( source );

    GARNET_VALIDATE_RETURN_ERRCODE(!destination, EINVAL);
    GARNET_VALIDATE_RETURN_ERRCODE(!source, EINVAL);
    GARNET_VALIDATE_RETURN_ERRCODE(dst_len > number_of_elements, ERANGE);

    dst_last    = destination + number_of_elements;
    p          += dst_len;
    for ( i = 0; i < src_len; ++ i ) {
        if ( p == dst_last )
            break;

        p[i]    = source[i];
    }
    eos(p, i);

    return 0;
}
