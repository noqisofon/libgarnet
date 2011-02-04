/* -*- encoding: utf-8; -*- */
/**
 * @file    gtypes.h
 * @since   %create-timestamp%
 * @brief   libgarnet で使う型エイリアス。
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

    $Id gtypes.h %timestamp% %author% $
 */
#ifndef garnet_gtypes_h
#define garnet_gtypes_h

#include <stdint.h>


#ifndef GARNET_DEFINE_VALUE
typedef     void*       VALUE;
#   define      GARNET_DEFINE_VALUE
#endif  /* ndef GARNET_DEFINE_VALUE */

#ifndef GARNET_DEFINE_GINT
typedef     int32_t       gint;
#   define      GARNET_DEFINE_GINT
#endif  /* GARNET_DEFINE_GUINT */

#ifndef GARNET_DEFINE_GUINT
typedef     uint32_t       guint;
#   define      GARNET_DEFINE_GUINT
#endif  /* GARNET_DEFINE_GUINT */

#ifndef GARNET_DEFINED_GCHAR
typedef     char        gchar;
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


#endif  /* garnet_gtypes_h */
