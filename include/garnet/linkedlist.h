#ifndef garnet_linkedlist_h
#define garnet_linkedlist_h

#include <garnet/types.h>
#include <garnet/linkedlist_node.h>


typedef struct {
    linkedlist_node*    head;
    linkedlist_node*    tail;
} GLinkedList;


GLinkedList*        g_linkedlist_create(void);


GLinkedList*        g_linkedlist_append(GLinkedList* self, variant_t value);


boolean_t           g_linkedlist_is_empty(GLinkedList* self);


linkedlist_node*    g_linkedlist_find(GLinkedList* self, variant_t value);


#endif  /* garnet_linkedlist_h */
