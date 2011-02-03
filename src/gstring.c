/* -*- encoding: utf-8; -*- */
/**
 * @file gstring.c
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

    $Id gstring.c %timestamp% %author% $
 */
#include <stdafx.h>

#include <string.h>

#include <garnet/galloc.h>
#include <garnet/gstring.h>

#include <cast.h>


/**
 * @def EMPTY_STRING
 * 空文字列を表します。
 */
#define     EMPTY_STRING        ""


/**
 * @def STRING_SENTINEL
 * 文字列の終わりを示す文字です。
 */
#define     STRING_SENTINEL     '\0'


/**
 *
 */
#define     SPUT(str, i, ch)    str[i] = ch


/**
 * @def EOS(str, i)
 * 文字列の指定された位置に \0 を代入します。
 */
#define     EOS(str, i)         SPUT(str, i, STRING_SENTINEL)


/**
 *
 */
#define     STR_TRUNCATE(pstr)  *pstr = STRING_SENTINEL


/**
 * 長さ n の文字列バッファを返します。
 */
static gchar* g_create_cstring(size_t n);


#if 0
size_t GARNET_API g_strlen(const gchar* self)
{
    size_t  i = 0;

    while ( *self ++ )
        i ++;

    return i;
}
#endif


gchar* GARNET_API g_strdup(const gchar* s)
{
    gchar*  result;
    size_t  insize;

    if ( s == NULL )
        return NULL;

    insize  = g_strlen( s );
    if ( insize == 0 )
        return EMPTY_STRING;
    result  = g_create_cstring( insize );

    return g_strncpy( result, s, insize + 1 );
}


gchar* GARNET_API g_strndup(const gchar* s, size_t n)
{
    gchar           *result, *it;
    const gchar*    stop;
    size_t          len;

    if ( s == NULL )
        return NULL;
    if ( n == 0 )
        return EMPTY_STRING;
    len     = g_strlen( s );
    if ( len == 0 )
        return EMPTY_STRING;

    result  = g_create_cstring( n );

    stop    = s + n;
    it      = result;
    while ( s != stop )
        *it ++   = *s ++;

    return result;
}


gchar* GARNET_API g_strnfill(size_t n, gchar ch)
{
    gchar    *result, *it, *stop;

    if ( n == 0 )
        return EMPTY_STRING;

    result  = g_create_cstring( n );

    it      = result;
    stop    = it + n;

    while ( it != stop )
        *it ++ = ch;

    *it = STRING_SENTINEL;

    return result;
}


gchar* GARNET_API g_str_assign(gchar* self, const gchar* other)
{
    size_t  other_len   = g_strlen( other );

    if ( other_len == 0 )
        return NULL;

    if ( !self )
        self    = g_create_cstring( gchar, other_len );
    else
        self    = REALLOC(gchar, self, other_len);

    return g_strncpy( self, other, other_len + 1 );
}


const gchar* GARNET_API g_strchr(const gchar* self, size_t n, gchar found_ch)
{
    const gchar*   last = self + n;

    for ( ; self != last; ++ self ) {
        if ( *self == found_ch )
            return self;
    }
    return last;
}


const gchar* GARNET_API g_strrchr(const gchar* s, size_t n, gchar found_ch)
{
    const gchar*   it;

    for ( it = s + n; it != s; -- it ) {
        if ( *it == found_ch )
            return it;
    }
    return it;
}


const gchar* GARNET_API g_str_find(const gchar* self, const gchar* search_text)
{
    gint    i;
    gint    matchc;
    size_t  search_text_len     = g_strlen( search_text );

    if ( search_text_len == 0 )
        return NULL;

    matchc  = 0;
    for ( i = 0; self[i] != STRING_SENTINEL; ++ i ) {
        if ( self[i] == search_text[matchc] )
            ++ matchc;

        if ( __STATIC_CAST(size_t, matchc) == search_text_len )
            return self + (i - (search_text_len - 1) );
    }
    return NULL;
}


const gchar* GARNET_API g_str_find_last_of(const gchar* self, const gchar* search_text)
{
    gint    i;
    gint    matchc;
    size_t  search_text_len     = g_strlen( search_text );

    const gchar*  p;

    matchc  = 0;
    p       = NULL;
    if ( search_text_len == 0 )
        return NULL;

    for ( i = 0; self[i] != STRING_SENTINEL; ++ i ) {
        if ( self[i] == search_text[matchc] )
            ++ matchc;

        if ( __STATIC_CAST(size_t, matchc) == search_text_len )
            p   = self + (i - (search_text_len - 1) );
    }
    return p;
}


gint GARNET_API g_str_index_of(const gchar* self, const gchar* search_text)
{
    gint    i;
    gint    matchc;
    size_t  search_text_len;

    search_text_len     = g_strlen( search_text );
    if ( search_text_len == 0 )
        return -1;
    
    matchc  = 0;
    for ( i = 0; self[i] != STRING_SENTINEL; ++ i ) {
        if ( self[i] == search_text[matchc] )
            ++ matchc;

        if ( __STATIC_CAST(size_t, matchc) == search_text_len )
            return i - __STATIC_CAST(gint, search_text_len - 1);
    }
    return -1;
}


gint GARNET_API g_str_last_index_of(const gchar* self, const gchar* search_text)
{
    gint    i;
    gint    matchc;
    gint    result_index;
    size_t  search_text_len;

    result_index        = -1;
    search_text_len     = g_strlen( search_text );
    if ( search_text_len == 0 )
        return result_index;

    matchc              = 0;
    search_text_len     = g_strlen( search_text );

    for ( i = 0; self[i] != STRING_SENTINEL; ++ i ) {
        if ( self[i] == search_text[matchc] )
            ++ matchc;

        if ( __STATIC_CAST(size_t, matchc) == search_text_len )
            result_index = i - __STATIC_CAST(gint, search_text_len - 1);
    }
    return result_index;
}


gboolean GARNET_API g_str_equal(const gchar* left, const gchar* right)
{
    return g_str_equal_len( left, g_strlen( left ), right, g_strlen( right ) );
}
gboolean GARNET_API g_str_equal_len(const gchar* left, size_t left_len, const gchar* right, size_t right_len)
{
    size_t  i;

    if ( left_len != right_len )
        return false;

    for ( i = 0; i < left_len; ++ i) {
        if ( left[i] != right[i] )
            return false;
    }
    return true;
}


gboolean GARNET_API g_str_startswith(const gchar* self, const gchar* prefix)
{
    size_t  self_length     = g_strlen( self );
    size_t  prefix_length   = g_strlen( prefix );

    if ( self_length < prefix_length )
        return false;

    while ( *prefix ) {
        if ( *prefix ++ != *self ++ )
            return false;
    }
    return true;
}


gchar* GARNET_API g_str_append(gchar* self, const gchar* appendee)
{
    gchar*  p;
    size_t  self_len;

    self_len    = g_strlen( self );
    p           = self + self_len;

    while ( *p ++ = *appendee ++ )
        ;

    return p;
}


gchar* GARNET_API g_str_appendch(gchar* self, gchar appendee)
{
    gchar*   p  = self + g_strlen( self );

    *p ++   = appendee;

    return p;
}


gchar* GARNET_API g_str_concat(const gchar* self, const gchar* right)
{
    gchar   *ret, *p;
    size_t  self_len, right_len;

    if ( !self || !right ) {
        if ( !self && right )
            return g_strdup( right );
        else if ( self && right )
            return g_strdup( self );
        else
            return NULL;
    }

    self_len    = g_strlen( self );
    right_len   = g_strlen( right );

    ret = g_create_cstring( self_len + right_len );
    p   = g_strcpy( ret, self ) + self_len;
    p   = g_strcpy( p, right ) + right_len;

    return ret;
}


gint GARNET_API g_str_char_at(const gchar* self, gint n)
{
    size_t  len;

    if ( !self )
        return -1;
    len     = g_strlen( self );
    if ( 0 > n || __STATIC_CAST(gint, len) < n )
        return -1;

    return self[n];
}


gchar* GARNET_API g_str_slice(const gchar* self, gint n, gint m)
{
    gchar*  result;
    size_t  i, self_length, result_length;

    if ( !self )
        return NULL;
    self_length = g_strlen( self );
    if ( n + m < __STATIC_CAST(gint, self_length) )
        return NULL;
    if ( n < 0 || m < 0 )
        return NULL;
    if ( n > m || n == m )
        return NULL;

    result_length   = (m - n) + 1;
    result  = g_create_cstring( result_length );

    for ( i = 0; i < result_length; ++ i ) {
        if ( self[i + n] == STRING_SENTINEL )
            break;

        SPUT(result, i, self[i + n]);
    }
    EOS(result, i);

    return result;
}


gchar* GARNET_API g_str_slice_last(const gchar* self, gint n)
{
    return g_str_slice( self, n, __STATIC_CAST(gint, g_strlen( self ) - 1) );
}


static gchar* g_create_cstring(size_t n)
{
    return g_new(gchar, n + 1);
}
