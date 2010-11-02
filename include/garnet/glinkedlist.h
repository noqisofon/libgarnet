/**
 * @file glinkedlist.h
 * @since 2010-10-13T09:31:23+0900
 */
#ifndef garnet_glinkedlist_h
#define garnet_glinkedlist_h

#include "_garnet.h"


/**
 * リンクリストのノードです。
 */
typedef struct g_linkedlist_t {
    struct g_linkedlist_t*      head;
    VALUE                       value;
    struct g_linkedlist_t*      tail;
} GList;


/**
 * リストの末尾に item を入れたノードを追加します。
 */
GList*  g_list_add(GList* self, VALUE item);


/**
 * リストの先頭に item を追加します。
 */
GList*  g_list_add_front(GList* self, VALUE item);


/**
 * リストの position 番目に item を挿入します。
 */
GList*  g_list_insert(GList* self, VALUE item, gint position);


/**
 * 指定されたリストの先頭のノードを返します。
 */
GList*  g_list_front(GList* self);


/**
 * 指定されたリストの末尾のノードを返します。
 */
GList*  g_list_behind(GList* self);


/**
 * 指定されたリストのサイズを返します。
 */
size_t  g_list_length(GList* self);


/**
 * リストの position 番目のノードを返します。
 */
GList*  g_list_advance(GList* self, gint distance);


/**
 * リストから指定された値が入っているノードを検索します。
 */
GList*  g_list_find(GList* self, VALUE found);


/**
 * 指定されたリストが使っているメモリを全て開放します。
 */
void    g_list_free(GList* self);


#endif  /* garnet_glinkedlist_h */
