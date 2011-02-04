/* -*- encoding: utf-8; -*- */
/**
 * @file glinkedlist.c
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

    $Id glinkedlist.c %timestamp% %author% $
 */
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
    if ( !self )
        return self;

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
