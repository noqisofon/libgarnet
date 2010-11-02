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
 * 文字列の終を示す文字です。
 */
#define     STRING_SENTINEL     '\0'


/**
 * 長さ n の文字列バッファを返します。
 */
static gchar* g_create_cstring(size_t n);


#if 0
size_t g_strlen(const gchar* self)
{
    size_t  i = 0;

    while ( *self ++ )
        i ++;

    return i;
}
#endif


gchar* g_strdup(const gchar* s)
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


gchar* g_strndup(const gchar* s, size_t n)
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


gchar* g_strnfill(size_t n, gchar ch)
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


gchar* g_str_assign(gchar* self, const gchar* other)
{
    size_t  other_len   = g_strlen( other );

    if ( other_len == 0 )
        return NULL;

    if ( *self )
        self    = g_new(gchar, other_len);
    else
        self    = REALLOC(gchar, self, other_len);

    return g_strncpy( self, other, other_len + 1 );
}


const gchar* g_strchr(const gchar* self, size_t n, gchar found_ch)
{
    const gchar*   last = self + n;

    for ( ; self != last; ++ self ) {
        if ( *self == found_ch )
            return self;
    }
    return last;
}


const gchar* g_strrchr(const gchar* s, size_t n, gchar found_ch)
{
    const gchar*   it;

    for ( it = s + n; it != s; -- it ) {
        if ( *it == found_ch )
            return it;
    }
    return it;
}


const gchar* g_str_find(const gchar* self, const gchar* search_text)
{
    int     i;
    int     matchc              = 0;
    size_t  search_text_len     = g_strlen( search_text );

    if ( search_text_len == 0 )
        return NULL;

    for ( i = 0; self[i] != STRING_SENTINEL; ++ i ) {
        if ( self[i] == search_text[matchc] )
            ++ matchc;

        if ( __STATIC_CAST(size_t, matchc) == search_text_len )
            return self + (i - (search_text_len - 1) );
    }
    return NULL;
}


const gchar* g_str_find_last_of(const gchar* self, const gchar* search_text)
{
    int     i;
    int     matchc              = 0;
    size_t  search_text_len     = g_strlen( search_text );

    gchar*  p;

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


int g_str_index_of(const gchar* self, const gchar* search_text)
{
    int     i;
    int     matchc              = 0;
    size_t  search_text_len     = g_strlen( search_text );

    if ( search_text_len == 0 )
        return -1;

    for ( i = 0; self[i] != STRING_SENTINEL; ++ i ) {
        if ( self[i] == search_text[matchc] )
            ++ matchc;

        if ( __STATIC_CAST(size_t, matchc) == search_text_len )
            return i - (search_text_len - 1);
    }
    return -1;
}


gboolean g_str_equal(const gchar* left, const gchar* right)
{
    return g_str_equal_len( left, g_strlen( left ), right, g_strlen( right ) );
}
gboolean g_str_equal_len(const gchar* left, size_t left_len, const gchar* right, size_t right_len)
{
    int i;

    if ( left_len != right_len )
        return false;

    for ( i = 0; i < left_len; ++ i) {
        if ( left[i] != right[i] )
            return false;
    }
    return true;
}


gboolean g_str_startswith(const gchar* self, const gchar* prefix)
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


gchar* g_str_append(gchar* self, const gchar* appendee)
{
    gchar*  p;
    size_t  self_len;

    self_len    = g_strlen( self );
    p           = self + self_len;

    while ( *p ++ = *appendee ++ )
        ;

    return p;
}


gchar* g_str_appendch(gchar* self, gchar appendee)
{
    gchar*   p  = self + g_strlen( self );

    *p ++   = appendee;

    return p;
}


gchar* g_str_concat(const gchar* self, const gchar* right)
{
    gchar   *ret, *p;
    size_t  self_len, right_len;

    self_len    = g_strlen( self );
    right_len   = g_strlen( right );

    ret = g_create_cstring( self_len + right_len );
    p   = g_strcpy( ret, self ) + self_len;
    p   = g_strcpy( p, right ) + right_len;

    return ret;
}


gint g_str_char_at(const gchar* self, gint n)
{
    size_t  len;

    if ( !self )
        return -1;
    len     = g_strlen( self );
    if ( 0 > n || __STATIC_CAST(gint, len) < n )
        return -1;

    return self[n];
}


static gchar* g_create_cstring(size_t n)
{
    return g_new(gchar, n + 1);
}
