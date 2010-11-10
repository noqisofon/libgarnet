#include <stdafx.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

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
    p   = NULL;
}


static void g_malloc_failed(size_t request_size)
{
    fprintf( stderr, "memory allocation failed at %d\n", request_size );

    g_exit( 1 );
}


static void g_realloc_failed(VALUE base_p, size_t request_size)
{
    fprintf( stderr, "memory allocation failed at %d from 0x%p\n", request_size, base_p );

    g_exit( 1 );
}
