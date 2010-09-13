#include <garnet/memoryman.h>
#include <garnet/linkedlist.h>


linkedlist_node* g_linkedlist_node_new(variant_t value)
{
    linkedlist_node*    result;

    result = (linkedlist_node *)g_malloc( sizeof(linkedlist_node) );
    result->prev    = NULL;
    result->value   = value;
    result->next    = NULL;

    return result;
}
linkedlist_node* g_linkedlist_node_new(variant_t value, linkedlist_node* prev)
{
    linkedlist_node*    result;

    result = (linkedlist_node *)g_malloc( sizeof(linkedlist_node) );

    prev->next      = result;

    result->prev    = prev;
    result->value   = value;
    result->next    = NULL;

    return result;
}


linkedlist_node* g_linkedlist_node_link(linkedlist_node* self, linkedlist_node* next)
{
    if ( self == NULL )
        return NULL;

    self->next  = next;
    next->prev  = self;

    return self;
}


linkedlist_node* g_linkedlist_node_next(linkedlist_node* self)
{
    if ( self == NULL )
        return NULL;

    return self->next;
}


variant_t g_linkedlist_node_value(linkedlist_node* self)
{
    if ( self == NULL )
        return NULL;

    return self->value;
}


linkedlist_node* g_linkedlist_node_prev(linkedlist_node* self)
{
    if ( self == NULL )
        return NULL;

    return self->prev;
}
