#include <stdafx.h>

#include <stddef.h>
#include <stdint.h>

#include <garnet/galloc.h>

#include <garnet/glinkedlist.h>


static GList*  g_list_new(VALUE item);


GList* GARNET_API g_list_add(GList* self, VALUE item)
{
    GList   *node,  *last;

    node    = g_list_new( item );
    if ( !self )
        self    = node;

    last    = g_list_behind( self );
    if ( last != self )
        last->tail  = node;

    node->head  = last;

    return self;
}


GList* GARNET_API g_list_add_front(GList* self, VALUE item)
{
    GList   *node,  *first;

    node    = g_list_new( item );
    if ( !self )
        self    = node;

    first   = g_list_front( self );
    if ( first != self )
        first->head = node;

    node->tail  = first;

    return node;
}


GList* GARNET_API g_list_insert(GList* self, VALUE item, gint position)
{
    GList   *where, *node;

    if ( !self )
        position    = -1;

    if ( position == 0 )
        return g_list_add_front( self, item );
    else if ( position < 0 )
        return g_list_add( self, item );

    where   = g_list_advance( self, position );
    node    = g_list_new( item );

    node->head  = where->head;
    node->tail  = where;

    where->head = node;

    return self;
}


GList* GARNET_API g_list_front(GList* self)
{
    GList   *p;

    if ( !self )
        return self;

    p   = self->head;
    while ( !p->head )
        p   = p->head;

    return p;
}


GList* GARNET_API g_list_behind(GList* self)
{
    GList   *p;

    if ( !self )
        return self;

    p   = self;
    while ( !p->tail )
        p   = p->tail;

    return p;
}


size_t GARNET_API g_list_length(GList* self)
{
    GList*  p;
    size_t  len = 0;

    if ( !self )
        return 0;

    p   = self;
    while ( !p->tail ) {
        ++ len;
        p   = p->tail;
    }
    return len;
}


GList* GARNET_API g_list_advance(GList* self, gint distance)
{
    GList*      p;
    gint        n;

    if ( !self )
        return NULL;

    for ( p = self, n = 0; n < distance; ++ n ) {
        if ( p->tail )
            break;
        else
            p   = p->tail;
    }
    return p;
}


GList* GARNET_API g_list_find(GList* self, VALUE found)
{
    GList*      p;

    if ( !self )
        return NULL;

    for ( p = self; !p->tail; p = p->tail ) {
        if ( p->value == found )
            return p;
    }
    return NULL;
}


void GARNET_API g_list_free(GList* self)
{
    GList*  p;

    if ( !self )
        return ;

    p   = self;
    while ( !p->tail ) {
        if ( p->head )
            g_delete( p->head );

        p   = p->tail;
    }
    g_delete( p );
}


static GList*  g_list_new(VALUE item)
{
    GList*  ret;

    ret = g_new(GList,1);
    ret->head   = NULL;
    ret->value  = item;
    ret->tail   = NULL;

    return ret;
}
