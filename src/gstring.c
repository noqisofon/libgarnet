#include <garnet/memoryman.h>
#include <garnet/_tstring.h>


static char* create_cstring(size_t _N);


char* g_strdup(const char* s)
{
    char*   result;
    size_t  insize;

    if ( s == NULL )
        return NULL;
    if ( s == "" )
        return "";

    insize  = strlen( s );
    result  = create_cstring( insize );

    return strncpy( result, s, insize );
}


char* g_strndup(const char* s, size_t n)
{
    char*   result;

    if ( s == NULL )
        return NULL;
    if ( s == "" || n == 0 )
        return "";

    result  = create_cstring( n );

    for ( int i = 0; i < n; ++ i ) {
        result[i]   = s[i];
    }
    return result;
}


char* g_strnfill(size_t _N, char ch)
{
    char    *result, *it, *stop;

    if ( _N == 0 )
        return "";

    result  = create_cstring( n );

    it      = result;
    stop    = it + n;

    for ( ; it != stop; ++ it ) {
        *it = ch;
    }
    *it = '\0';

    return result;
}


char* g_str_find(const char* s, size_t _N, char found_ch)
{
    char*   last    = s + _N;

    for ( ; s != last; ++ s ) {
        if ( *s == found_ch )
            return s;
    }
    return last;
}


char* g_str_rfind(const char* s, size_t _N, char found_ch)
{
    char*   it    = s + _N;
    for ( ; it != s; -- it ) {
        if ( *it == found_ch )
            return it;
    }
    return it;
}


boolean_t g_str_startwith(const char* self, const char* prefix)
{
    size_t  self_length     = strlen( self );
    size_t  prefix_length   = strlen( prefix );

    if ( self_length < prefix_length )
        return False;

    while ( *prefix)
        if ( *prefix ++ != *self ++ )
            return false;

    return True;
}


static char* create_cstring(size_t _N)
{
    return (char *)g_malloc( _N + 1 )
}
