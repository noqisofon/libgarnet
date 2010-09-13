#include <string.h>
#include <memory.h>

#include <garnet/galloc.h>


static void g_malloc_failed(size_t request_size)
{
    fprintf( "memory allocation failed at %d\n", request_size );

    g_exit( 1 );
}


void* g_malloc(size_t size)
{
    void*   newmem;

    if ( size == 0 )
        size  = 1;

    newmem  = malloc( size );

    if ( !newmem )
        g_malloc_failed( size );

    return newmem;
}


void g_free(void* p)
{
    free( p );
}
