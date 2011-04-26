/**
 * \file galloc.c
 * \since %create-timestamp%
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

    $Id galloc.c %timestamp% noqisofon $
 */
#include <stdafx.h>

#include <string.h>
#include <memory.h>

#ifdef GARNET_BUILD
#   include <garnet/_garnet.h>
#endif  /* def GARNET_BUILD */
#include <garnet/gthread.h>
#include <garnet/galloc.h>


static void g_malloc_failed(size_t request_size);
static void g_realloc_failed(VALUE base_p, size_t request_size);


VALUE GARNET_API g_malloc(size_t size)
{
    VALUE   newmem;

    if ( size == 0 )
        size  = 1;
    newmem  = malloc( size );
    if ( !newmem )
        g_malloc_failed( size );

    return newmem;
}


VALUE GARNET_API g_malloc2(size_t n, size_t size)
{
    if ( n == 0 )
        n       = 1;
    if ( size == 0 )
        size    = 1;

    return g_malloc( size * n );
}


VALUE GARNET_API g_calloc(size_t n, size_t size)
{
    VALUE   newmem;

    if ( size == 0 )
        size  = 1;
    newmem  = calloc( n, size );
    if ( !newmem )
        g_malloc_failed( size );

    return newmem;
}


VALUE GARNET_API g_realloc(VALUE p, size_t size)
{
    VALUE   newmem;

    if ( size == 0 )
        size  = 1;
    newmem  = realloc( p, size );
    if ( !newmem )
        g_realloc_failed( p, size );

    return newmem;
}


void GARNET_API g_free(VALUE p)
{
    free( p );
    if ( !p )
        p   = NULL;
}


static void g_malloc_failed(size_t request_size)
{
    g_fprintf( stderr, "memory allocation failed at %d\n", request_size );

    g_exit( 1 );
}


static void g_realloc_failed(VALUE base_p, size_t request_size)
{
    g_fprintf( stderr, "memory allocation failed at %d from 0x%p\n", request_size, base_p );

    g_exit( 1 );
}
// Local Variables:
//   coding: shift_jis-dos
// End:
// galloc.c ends here
