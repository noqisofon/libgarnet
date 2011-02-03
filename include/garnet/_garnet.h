/* -*- encoding: utf-8; -*- */
/**
 * @file _garnet.h
 * @since %create-timestamp%
 * 
 */
/*
    Copyright (c) %year% %full-author% %author-email%

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

    $Id _garnet.h %timestamp% %author% $
 */
#ifndef garnet__garnet_h
#define garnet__garnet_h

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#ifdef GARNET_HAS_GTYPES_H
#   include <garnet/gtypes.h>
#endif  /* def GARNET_HAS_GTYPES_H */


#ifndef GARNET_DEFINE_VALUE
typedef     void*       VALUE;
#   define      GARNET_DEFINE_VALUE
#endif  /* GARNET_DEFINE_VALUE */

#ifndef GARNET_DEFINED_GCHAR
#   if defined(_UNICODE) || defined(UNICODE)
typedef     wchar_t     gchar;
#else
typedef     char        gchar;
#endif  /* defined(_UNICODE) || defined(UNICODE) */
#   define      GARNET_DEFINED_GCHAR
#endif  /* ndef GARNET_DEFINED_GCHAR */

#ifndef GARNET_DEFINED_GBOOLEAN
#   ifndef __cplusplus
typedef enum tag_boolean {
    false   = 0,
    true    = 1
} gboolean;
#   else
typedef     bool        gboolean;
#   endif  /* ndef __cplusplus */
#   define      GARNET_DEFINED_GBOOLEAN
#endif  /* def GARNET_DEFINED_GBOOLEAN */


#endif  /* garnet__garnet_h */
