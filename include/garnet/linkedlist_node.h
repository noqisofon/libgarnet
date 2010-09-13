#ifndef garnet_linkedlist_node_h
#define garnet_linkedlist_node_h

#include <garnet/types.h>


typedef struct _linkedlist_node {
    struct _linkedlist_node*    prev;
    variant_t                   value;
    struct _linkedlist_node*    next;
} linkedlist_node;


linkedlist_node*    g_linkedlist_node_new(variant_t value);
linkedlist_node*    g_linkedlist_node_new(variant_t value, linkedlist_node* prev);


linkedlist_node*    g_linkedlist_node_link(linkedlist_node* self, linkedlist_node* next);


linkedlist_node*    g_linkedlist_node_swap(linkedlist_node* self, linkedlist_node* other);


linkedlist_node*    g_linkedlist_node_next(linkedlist_node* self);


variant_t           g_linkedlist_node_value(linkedlist_node* self);


linkedlist_node*    g_linkedlist_node_prev(linkedlist_node* self);


#endif  /* garnet_linkedlist_node_h */
