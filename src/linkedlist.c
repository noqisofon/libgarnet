#include <garnet/linkedlist.h>


GLinkedList* g_linkedlist_create(void)
{
    GLinkedList*    result;

    result  = (GLinkedList *)g_malloc( sizeof(GLinkedList) );
    result->tail    = result->head  = NULL;

    return result;
}


GLinkedList* g_linkedlist_append(GLinkedList* self, variant_t value)
{
    return g_linkedlist_link( self, g_linkedlist_node_new( value ) );
}


GLinkedList* g_linkedlist_link(GLinkedList* self, linkedlist_node* linkee)
{
    if ( self->head == NULL)
        self->tail  = self->head  = linkee;
    else
        self->tail  = g_linkedlist_node_link( self->tail, linkee );

    return self;
}


boolean_t g_linkedlist_is_empty(GLinkedList* self)
{
    if ( self == NULL )
        return True;

    return self->head == NULL? True: False;
}

